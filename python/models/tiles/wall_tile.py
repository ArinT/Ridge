__author__ = 'Arin'
from tile import Tile
import os

path = [
os.path.join("pixel_art","wall.png"),
os.path.join("pixel_art","walll.png"),
os.path.join("pixel_art","wallu.png"),
os.path.join("pixel_art","wallr.png"),
os.path.join("pixel_art","walld.png"),
os.path.join("pixel_art","wallv.png"),
os.path.join("pixel_art","wallf.png"),
os.path.join("pixel_art","wallg.png")]


class WallTile(Tile):
    """Subclass which calls tile superclass constructor to initiate"""
    key = "Wall"
    def __init__(self, x, y, dir = 0):
        super(WallTile, self).__init__("X", path[dir], False, x, y)#hook up image
