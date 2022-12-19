#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include "map.h"
using namespace std;
const int kCost1 = 10; //直移一格消耗
const int kCost2 = 14; //斜移一格消耗

struct Point
{
    int x, y; //點座標，這裡為了方便按照C++的陣列來計算，x代表橫排，y代表豎列
    int F, G, H; //F=G+H
    Point *parent; //parent的座標，這裡沒有用指標，從而簡化程式碼
    Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL)  //變數初始化
    {
    }
};

class Astar
{
public:
    void InitAstar(std::vector<std::vector<int>> &_maze);
    list<Point *> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);

private:
    Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
    vector<Point *> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;
    bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const; //判斷某點是否可以用於下一步判斷
    Point *isInList(const std::list<Point *> &list, const Point *point) const; //判斷開啟/關閉列表中是否包含某點
    Point *getLeastFpoint(); //從開啟列表中返回F值最小的節點
    //計算FGH值
    int calcG(Point *temp_start, Point *point);
    int calcH(Point *point, Point *end);
    int calcF(Point *point);
private:
    vector<std::vector<int>> maze;
    list<Point *> openList;  //開啟列表
    list<Point *> closeList; //關閉列表
};
void Astar::InitAstar(std::vector<std::vector<int>> &_maze)
{
    maze = _maze;
}

int Astar::calcG(Point *temp_start, Point *point)
{
    int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y)) == 1 ? kCost1 : kCost2;
    int parentG = point->parent == NULL ? 0 : point->parent->G; //如果是初始節點，則其父節點是空
    return parentG + extraG;
}

int Astar::calcH(Point *point, Point *end)
{
    //用簡單的歐幾里得距離計算H，這個H的計算是關鍵，還有很多演算法，沒深入研究^_^
    return sqrt((double)(end->x - point->x)*(double)(end->x - point->x) + (double)(end->y - point->y)*(double)(end->y - point->y))*kCost1;
}

int Astar::calcF(Point *point)
{
    return point->G + point->H;
}

Point *Astar::getLeastFpoint()
{
    if (!openList.empty())
    {
        auto resPoint = openList.front();
        for (auto &point : openList)
            if (point->F<resPoint->F)
                resPoint = point;
        return resPoint;
    }
    return NULL;
}

Point *Astar::findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner)
{
    openList.push_back(new Point(startPoint.x, startPoint.y)); //置入起點,拷貝開闢一個節點，內外隔離
    while (!openList.empty())
    {
        auto curPoint = getLeastFpoint(); //找到F值最小的點
        openList.remove(curPoint); //從開啟列表中刪除
        closeList.push_back(curPoint); //放到關閉列表
        //1,找到當前周圍八個格中可以通過的格子
        auto surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);
        for (auto &target : surroundPoints)
        {
            //2,對某一個格子，如果它不在開啟列表中，加入到開啟列表，設定當前格為其父節點，計算F G H
            if (!isInList(openList, target))
            {
                target->parent = curPoint;

                target->G = calcG(curPoint, target);
                target->H = calcH(target, &endPoint);
                target->F = calcF(target);

                openList.push_back(target);
            }
                //3，對某一個格子，它在開啟列表中，計算G值, 如果比原來的大, 就什麼都不做, 否則設定它的父節點為當前點,並更新G和F
            else
            {
                int tempG = calcG(curPoint, target);
                if (tempG<target->G)
                {
                    target->parent = curPoint;

                    target->G = tempG;
                    target->F = calcF(target);
                }
            }
            Point *resPoint = isInList(openList, &endPoint);
            if (resPoint)
                return resPoint; //返回列表裡的節點指標，不要用原來傳入的endpoint指標，因為發生了深拷貝
        }
    }

    return NULL;
}

std::list<Point *> Astar::GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner)
{
    Point *result = findPath(startPoint, endPoint, isIgnoreCorner);
    list<Point *> path;
    //返回路徑，如果沒找到路徑，返回空連結串列
    while (result)
    {
        path.push_front(result);
        result = result->parent;
    }

    // 清空臨時開閉列表，防止重複執行GetPath導致結果異常
    openList.clear();
    closeList.clear();

    return path;
}

Point *Astar::isInList(const std::list<Point *> &list, const Point *point) const
{
    //判斷某個節點是否在列表中，這裡不能比較指標，因為每次加入列表是新開闢的節點，只能比較座標
    for (auto p : list)
        if (p->x == point->x&&p->y == point->y)
            return p;
    return NULL;
}

bool Astar::isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const
{
    if (target->x<0 || target->x>maze.size() - 1
        || target->y<0 || target->y>maze[0].size() - 1
        || maze[target->x][target->y] == 1
        || target->x == point->x&&target->y == point->y
        || isInList(closeList, target)) //如果點與當前節點重合、超出地圖、是障礙物、或者在關閉列表中，返回false
        return false;
    else
    {
        if (abs(point->x - target->x) + abs(point->y - target->y) == 1) //非斜角可以
            return true;
        else
        {
            //斜對角要判斷是否絆住
            if (maze[point->x][target->y] == 0 && maze[target->x][point->y] == 0)
                return true;
            else
                return isIgnoreCorner;
        }
    }
}

std::vector<Point *> Astar::getSurroundPoints(const Point *point, bool isIgnoreCorner) const
{
    std::vector<Point *> surroundPoints;

    for (int x = point->x - 1; x <= point->x + 1; x++)
        for (int y = point->y - 1; y <= point->y + 1; y++)
            if (isCanreach(point, new Point(x, y), isIgnoreCorner))
                surroundPoints.push_back(new Point(x, y));

    return surroundPoints;
}
int main()
{
    //初始化地圖，用二維矩陣代表地圖，1表示障礙物，0表示可通

    Astar astar;
    astar.InitAstar(maze);

    //設定起始和結束點
    Point start(1, 1);
    Point end(6, 10);
    //A*演算法找尋路徑
    list<Point *> path = astar.GetPath(start, end, false);
    //列印
    for (auto &p : path)
        cout << '(' << p->x << ',' << p->y << ')' << endl;

    system("pause");
    return 0;
}