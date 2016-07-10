__author__ = 'Arin'
from models.tiles.wall_tile import WallTile
from models.tiles.scenery_tile import SceneryTile
from models.tiles.concrete_tile import ConcreteTile
from models.tiles.road_tile import RoadTile
from models.tiles.grass_tile import GrassTile
from models.tiles.special_tile import SpecialTile
from models.units.constants import CONST
from models.units.greaser_unit import GreaserUnit
from models.units.bruiser_unit import BruiserUnit
from models.units.squabbler_unit import SquabblerUnit
import time
import os
import pygame


class Map():
    def __init__(self, col, row):
        self.columns = col
        self.rows = row
        self.tile_matrix = [[None for x in xrange(row)] for x in xrange(col)]
        self.unit_list = []
        self.sharks_turn = True
        self.turn_start = time.time()
        self.turn_sound = load_sound(CONST.turn_sound)

    def generate_from_ascii(self, path_to_txt):
        """Generates a map from a text file"""
        f = open(path_to_txt)
        for i in range(self.rows):
            line = f.readline()
            for j in range(self.columns):
                self.lay_tile(line[j], j, i)

    def unit_at(self, col, row):
        """neat getter"""
        return self.tile_matrix[col][row].unit

    def is_occupied(self, x, y):
        """neat getter"""
        return self.tile_matrix[x][y].is_occupied
    def is_accessible(self,x,y):
        """neat getter"""
        return self.tile_matrix[x][y].is_accessible
    def add_unit(self, unit):
        """Neat way to add a unit"""
        if self.is_occupied(unit.x, unit.y):
            del unit
            raise BadAddException("Already a unit there")
        self.tile_matrix[unit.x][unit.y].add_unit(unit)
        self.unit_list.append(unit)

    def delete_unit(self, unit):
        """Neat way to delete unit"""
        self.unit_list.remove(unit)
        self.tile_matrix[unit.x][unit.y].remove_unit()
        del unit

    def lay_tile(self, char, col, row):
        """Adds a tile to the tile matrix"""
        if char == 'R':
            self.tile_matrix[col][row] = RoadTile(col, row)
        elif char == 'T':
            self.tile_matrix[col][row] = RoadTile(col, row,1)
        elif char == 'C':
            self.tile_matrix[col][row] = ConcreteTile(col, row)
        elif char == 'G':
            self.tile_matrix[col][row] = GrassTile(col, row)
        elif char == 'W':
            self.tile_matrix[col][row] = WallTile(col, row)
        elif char == 'S':
            self.tile_matrix[col][row] = SceneryTile(col, row)
        elif char == '1':
            self.tile_matrix[col][row] = WallTile(col,row,1)
        elif char == '2':
            self.tile_matrix[col][row] = WallTile(col,row,2)
        elif char == '3':
            self.tile_matrix[col][row] = WallTile(col,row,3)
        elif char == '4':
            self.tile_matrix[col][row] = WallTile(col,row,4)
        elif char == 'V':
            self.tile_matrix[col][row] = WallTile(col,row,5)
        elif char == 'D':
            self.tile_matrix[col][row] = WallTile(col,row,6)
        elif char == 'F':
            self.tile_matrix[col][row] = WallTile(col,row,7)
        elif char == 'A':
            self.tile_matrix[col][row] = SpecialTile(col,row)
        elif char == 'Y':
            self.tile_matrix[col][row] = SpecialTile(col,row,1)
        elif char == 'U':
            self.tile_matrix[col][row] = SpecialTile(col,row,2)
        elif char == 'I':
            self.tile_matrix[col][row] = SpecialTile(col,row,3)
        elif char == 'O':
            self.tile_matrix[col][row] = SpecialTile(col,row,4)
        elif char == 'P':
            self.tile_matrix[col][row] = SpecialTile(col,row,5)
        elif char == 'L':
            self.tile_matrix[col][row] = SpecialTile(col,row,6)
        elif char == 'K':
            self.tile_matrix[col][row] = SpecialTile(col,row,7)
        elif char == 'J':
            self.tile_matrix[col][row] = SpecialTile(col,row,8)
        else:
            self.tile_matrix[col][row] = WallTile(col, row)

    def move_unit(self, path):
        """Moves unit from point a to be given there is a path"""
        unit = path[0].remove_unit()
        path[len(path) - 1].add_unit(unit)

    def a_star(self, start, goal, team, limit=CONST.max_movement):
        """a* pathfinding algorithm"""
        #Heuristic estimate of the distance to the goal tile
        dist = manhattan_distance(start, goal)
        open_set = set()
        open_set.add(Node(start, dist, None))  #Add start tile to search set
        closed_set = set()
        while open_set: #While there are nodes to search
            #finds tile in open set with minimum score
            current = min(open_set, key=lambda inst: inst.score)
            if current.tile == goal: #Base case
                return self.retrace_path(current) #return the path you took
            open_set.remove(current)
            closed_set.add(current.tile) # We've explored this tile
            for neighbor in self.neighboring_tiles(current, team):
                if neighbor not in closed_set and \
                                neighbor not in open_set: #if we haven't searched it yet
                    score = manhattan_distance(neighbor, goal)
                    if score <= limit:
                        open_set.add(Node(neighbor, score, current)) #search it
        return []

    def retrace_path(self, current):
        """Uses Node object to retrace the path taken"""
        path = [current.tile]
        while current.parent is not None:
            current = current.parent
            path.append(current.tile)
        path.reverse()
        return path

    def neighboring_tiles(self, current_node, team):
        """Finds neighboring tiles which you can travel to"""
        my_tile = current_node.tile
        neighbors = []
        up = my_tile.y + 1
        down = my_tile.y - 1
        right = my_tile.x + 1
        left = my_tile.x - 1
        if self.can_go_through(my_tile.x, up, team): #
            neighbors.append(self.tile_matrix[my_tile.x][up])
        if self.can_go_through(right, my_tile.y, team):
            neighbors.append(self.tile_matrix[right][my_tile.y])
        if self.can_go_through(my_tile.x, down, team):
            neighbors.append(self.tile_matrix[my_tile.x][down])
        if self.can_go_through(left, my_tile.y, team):
            neighbors.append(self.tile_matrix[left][my_tile.y])
        return neighbors
    def can_go_to(self, x, y):
        """Can a unit on this team move through this space"""
        #is the tile out of bounds? Is it accessible? Is it enemy occupied?
        return not self.out_of_bounds(x, y) and \
               self.is_accessible(x,y) and \
               not self.is_occupied(x, y)

    def can_go_through(self, x, y, team):
        """Can a unit on this team move through this space"""
        #is the tile out of bounds? Is it accessible? Is it enemy occupied?
        return not self.out_of_bounds(x, y) and \
               self.is_accessible(x,y) and \
               not self.is_enemy_occupied(x, y, team)

    def is_enemy_occupied(self, x, y, team):
        """If there is a unit here, is it friendly?"""
        return self.is_occupied(x, y) and \
               not self.unit_at(x, y).team == team

    def out_of_bounds(self, x, y):
        """Is this coordinate out of bounds?"""
        return x < 0 or x >= self.columns or y < 0 or y >= self.rows

    def sharks_routed(self):
        """No sharks remain"""
        for unit in self.unit_list:
            if unit.team == CONST.sharks:
                return False
        return True

    def jets_routed(self):
        """No jets remain"""
        for unit in self.unit_list:
            if unit.team == CONST.jets:
                return False
        return True
    def switch_turns(self):
        self.turn_sound.play()
        self.turn_start = time.time()
        self.sharks_turn = not self.sharks_turn
        for unit in self.unit_list:
            unit.ready= True
            if not self.your_turn(unit):
                unit.demoralize = False
    def unmark(self):
        for row in self.tile_matrix:
            for tile in row:
                tile.marked=False
                tile.at_marked = False
    def your_turn(self,unit ):
        team = unit.team
        return (self.sharks_turn and team == CONST.sharks) or\
               (not self.sharks_turn and team == CONST.jets)
    def quick_board_32_18(self):
        unit4 = GreaserUnit(12, 6, self, CONST.jets)
        unit5 = SquabblerUnit(14, 4, self, CONST.jets)
        unit6 = GreaserUnit(13, 5, self, CONST.jets)
        unit7 = SquabblerUnit(17,6, self, CONST.jets)
        unit8 = BruiserUnit(18,6,self,CONST.jets)
        unit1 = GreaserUnit(12, 15, self, CONST.sharks)
        unit2 = BruiserUnit(13, 16, self, CONST.sharks)
        unit3 = SquabblerUnit(16, 16, self, CONST.sharks)
        unit9 = BruiserUnit(17, 14,self,CONST.sharks)
        uni10 = GreaserUnit(14, 14, self, CONST.sharks)


def manhattan_distance(curr_tile, end_tile):
    return abs(curr_tile.x - end_tile.x) + abs(curr_tile.y - end_tile.y)


def print_path(path):
    """Prints a path. Useful for debugging"""
    for tile in path:
        print tile.x, tile.y


class Node(object):
    def __init__(self, tile, score, parent):
        self.tile = tile
        self.score = score
        self.parent = parent


class BadAddException(Exception):
    def __init__(self, msg):
        self.msg = msg
def load_sound(name):
        class NoneSound:
            def play(self): pass
        if not pygame.mixer:
            return NoneSound()
        fullname = os.path.join(os.path.abspath(os.path.curdir), name)
        try:
            sound = pygame.mixer.Sound(fullname)
        except MemoryError, message:
            sound = NoneSound()
        return sound
