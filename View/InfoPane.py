__author__ = 'Arin'
import pygame, os
from DummySprite import DummySprite
from DummyTileSprite import DummyTileSprite
from Models.Units.Constants import CONST
from Models.Units.BruiserUnit import BruiserUnit
from Models.Units.GreaserUnit import GreaserUnit
from Models.Units.SquabblerUnit import SquabblerUnit
from Models.Tiles.WallTile import WallTile
from Models.Tiles.SceneryTile import SceneryTile
from Models.Tiles.ConcreteTile import ConcreteTile
from Models.Tiles.GrassTile import GrassTile
from Models.Tiles.RoadTile import RoadTile
from Models.Tiles.SpecialTile import SpecialTile
import math

class InfoPane(object):
    """Cursor class. A small border which highlights your selected tile"""
    def __init__(self, cursor, map, parent):

        self.surface = pygame.Surface((180,180))
        self.surface.convert()
        self.surface.fill((255,255,155))
        self.cursor = cursor
        self.x = 0
        self.y = 0
        self.font = font = pygame.font.Font(None, 27)
        self.parent = parent
        self.map = map
        self.col=map.columns
        self.row=map.rows
        self.prev_x = self.row-3
        self.prev_y = self.col-3
        self.layer_pane = pygame.sprite.LayeredUpdates()
        self.initialize_dummies()

    def update(self):
        cursor_x = self.cursor.x
        cursor_y = self.cursor.y
        self.surface.fill((255,255,155))
        self.calculate_position(cursor_x, cursor_y)
        self.set_turn()
        self.set_tile_info(cursor_x,cursor_y)
        self.set_unit_info(cursor_x,cursor_y)
        self.set_unit_sprite(cursor_x, cursor_y)
        self.set_tile_sprite(cursor_x, cursor_y)
        self.draw_info_pane()
    def set_turn(self):
        turn = 'SHARKS TURN'if self.map.sharks_turn else 'JETS TURN'
        turn_text = self.font.render(turn, 1, (10,10,10))
        turn_textpos = turn_text.get_rect()
        turn_textpos.topleft = (30,80)
        self.surface.blit(turn_text,turn_textpos)

    def set_tile_info(self,x,y):
        tile = self.map.tile_matrix[x][y]
        defense = 'Def. Value: '+str(tile.defense_value)
        def_text = self.font.render(defense, 1, (10,10,10))
        def_textpos = def_text.get_rect()
        def_textpos.topleft = 63,160
        self.surface.blit(def_text,def_textpos)
        name = tile.key
        name_text = self.font.render(name,1,(10,10,10))
        name_textpos = name_text.get_rect()
        name_textpos.topleft = 63, 120
        self.surface.blit(name_text,name_textpos)
    def set_unit_info(self,x,y):
        unit = self.map.unit_at(x, y)
        if unit is None:
            return
        name = unit.key
        name_text = self.font.render(name,1,(10,10,10))
        name_textpos = name_text.get_rect()
        name_textpos.topleft = 60, 30
        self.surface.blit(name_text,name_textpos)
        health = self.get_health(unit)
        health_text = self.font.render(health,1,(10,10,10))
        health_textpos = health_text.get_rect()
        health_textpos.topleft = 60, 0
        self.surface.blit(health_text,health_textpos)

    def get_health(self,unit):
        ratio = unit.hp/unit.max_hp
        return 'EP: '+str(int(math.ceil(ratio*10)))+' / 10'
    def set_tile_sprite(self, x, y):
        tile = self.map.tile_matrix[x][y]
        self.draw_tile(tile)

    def set_unit_sprite(self, x, y):
        unit = self.map.unit_at(x, y)
        self.draw_unit(unit)

    def draw_info_pane(self):
        self.layer_pane.empty()
        self.layer_pane.add(self.sprite)
        self.layer_pane.add(self.tile_sprite)
        self.layer_pane.draw(self.surface)
        self.parent.blit(self.surface, (self.x, self.y))

    def calculate_position(self, x, y):
        xp = 0
        yp = 0
        if x < self.col / 2:
            xp = self.col - 3
        if y < self.row / 2:
            yp = self.row - 3
        self.x = xp * 60
        self.y = yp * 60
    def draw_tile(self, tile):
        self.tile_sprite = self.sprite_dict[tile.key]
    def draw_unit(self, unit):
        if unit is None:
            self.sprite = self.sprite_dict["none"][0]
            return
        unit_type = self.sprite_dict[unit.__class__.key]
        if unit.team == CONST.jets:
            self.sprite = unit_type[0]
        elif unit.team == CONST.sharks:
            self.sprite = unit_type[1]
    def initialize_dummies(self):
        self.sprite_dict = {}
        jets_gr = DummySprite(CONST.jt_gr_im_pathb,self)
        jets_br = DummySprite(CONST.jt_br_im_pathb,self)
        jets_sq = DummySprite(CONST.jt_sq_im_pathb,self)
        shrk_sq = DummySprite(CONST.sh_sq_im_pathb,self)
        shrk_br = DummySprite(CONST.sh_br_im_pathb,self)
        shrk_gr = DummySprite(CONST.sh_gr_im_pathb,self)
        road_tl = DummyTileSprite(CONST.rd_path,self)
        trash_tl = DummyTileSprite(CONST.tcr_path,self)
        grass_tl = DummyTileSprite(CONST.gs_path, self)
        wall_tl = DummyTileSprite(CONST.wall_path,self)
        concrete_tl = DummyTileSprite(CONST.cr_path,self)
        special_tl = DummyTileSprite(CONST.sp_path,self)
        self.sprite_dict[GreaserUnit.key] = [jets_gr, shrk_gr]
        self.sprite_dict[BruiserUnit.key] = [jets_br, shrk_br]
        self.sprite_dict[SquabblerUnit.key] = [jets_sq, shrk_sq]
        self.sprite_dict[RoadTile.key]= road_tl
        self.sprite_dict[SceneryTile.key]=trash_tl
        self.sprite_dict[GrassTile.key]=grass_tl
        self.sprite_dict[WallTile.key]=wall_tl
        self.sprite_dict[ConcreteTile.key]=concrete_tl
        self.sprite_dict[SpecialTile.key]=special_tl
        self.sprite_dict["none"] = [DummySprite(CONST.none,self)]

    def load_sprite(self, name):
        fullname = os.path.join(os.path.abspath(os.path.curdir), name)
        try:
            image = pygame.image.load(fullname)
        except pygame.error, message:
            print 'Cannot load image at:', name
            raise SystemExit, message
        image = image.convert_alpha()
        return image, image.get_rect()