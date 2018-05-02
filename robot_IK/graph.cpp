#include "graph.h"

byte wall_flags[] = {WALL_NOTH, WALL_EAST, WALL_SOUTH, WALL_WEST};

byte cycleShift(byte value, int count){
  value <<= count;
  return (value & 0b00111100) + ((value >> 4) & 0b00111100); 
}

void Memory::build_wall(byte wall_type, Point wall_pos){
  set_vert(wall_pos, get_vert(wall_pos) | wall_type);
}

byte Memory::get_vert(Point p){
  if (p.x < 0 || p.x > 15 || p.y < 0 || p.y > 15){
    return 0b00111111;
  }
  return maze_map[p.x][p.y];
}

void Memory::set_vert(Point p, byte value){
  if (p.x < 0 || p.x > 15 || p.y < 0 || p.y > 15){
    return;
  }
  maze_map[p.x][p.y] = value;
}

bool Memory::can_go(){
  byte cur_vertex = get_vert(cur_position);
  return wall_flags[cur_direction] & cur_vertex;
}

void Memory::next_action(){
  if (cur_action != A_NONE){
    return;
  }
  byte cur_vertex = get_vert(cur_position);
  Point next_point;
  Point edges[] = {
    Point(cur_position.x, cur_position.y + 1),
    Point(cur_position.x + 1, cur_position.y),
    Point(cur_position.x, cur_position.y - 1),
    Point(cur_position.x - 1, cur_position.y),
  };
  for (int i = 0; i < 4; i++){
    byte v = get_vert(edges[i]);
    if (!(v & (wall_flags[i] | IN_PROGRESS_FLAG))){
      stack.push_back(edges[i]);
      set_vert(edges[i], v | IN_PROGRESS_FLAG);
    }  
  }
}

void Memory::research_point(){
  byte cur_vertex = get_vert(cur_position);
  byte next_vertex = get_vert(next_point());
  if (cur_vertex & RESEARCH_FLAG){
    return;
  }

  byte frontSide = wall_flags[cur_direction];
  byte rightSide = cycleShift(frontSide, 1);
  byte backSide = cycleShift(frontSide, 2);
  byte leftSide = cycleShift(rightSide, 2);

  if (centralIK.IK){
    set_vert(cur_position, cur_vertex |= (frontSide | RESEARCH_FLAG));
  }
  
  if (cur_vertex & wall_flags[cur_direction]){
    if (rightIK.IK){
      set_vert(next_point(), next_vertex |= rightSide);  
    }
    if (leftIK.IK){
      set_vert(next_point(), next_vertex |= leftSide);  
    }
  }
}

Point Memory::next_point(){
  switch(cur_direction){
    case D_NOTH:
      return Point(cur_position.x, cur_position.y + 1);
    case D_EAST:
      return Point(cur_position.x + 1, cur_position.y);
    case D_SOUTH:
      return Point(cur_position.x, cur_position.y - 1);
    case D_WEST:
      return Point(cur_position.x - 1, cur_position.y);
  }
}

