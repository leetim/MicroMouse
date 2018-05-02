#pragma once
#include "motor.h"
#include "sensors.h"
#include <QList.h>

#define WALL_NOTH (byte)0b000100
#define WALL_EAST (byte)0b001000
#define WALL_SOUTH (byte)0b010000
#define WALL_WEST (byte)0b100000
#define RESEARCH_FLAG (byte)0b000010
#define IN_PROGRESS_FLAG (byte)0b000001

enum Direction{D_NOTH, D_EAST, D_SOUTH, D_WEST};
enum Action{A_NONE, A_GO_NOTH, A_GO_EAST, A_GO_SOUTH, A_GO_WEST};
//byte wall_flags[4];
//byte wall_flags[] = {WALL_NOTH, WALL_EAST, WALL_SOUTH, WALL_WEST};

struct Point{
  Point(): x(), y(){}
  Point(byte x, byte y): x(x), y(y){}
  byte x;
  byte y;
};

class Memory{
public:
  Point cur_position;
  Direction cur_direction;
  Action cur_action;
  byte maze_map[16][16];
  Cl_IK leftIK;
  Cl_IK centralIK;
  Cl_IK rightIK;

  Memory(Cl_IK leftIK, Cl_IK centralIK, Cl_IK rightIK): 
          leftIK(leftIK), centralIK(centralIK), rightIK(rightIK){};
  byte get_vert(Point point);
  void set_vert(Point point, byte value);
  void build_wall(byte wall_type, Point wall_pos);
  bool can_go();
  void next_action();
  void research_point();

  Point next_point();

private:
  QList<Point> stack;
};

// bfs(Point start, Memory mem){
//  
//}

