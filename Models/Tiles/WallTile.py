__author__ = 'Arin'
from Tile import Tile
import os

path = [
os.path.join("PixelArt","wall.png"),
os.path.join("PixelArt","walll.png"),
os.path.join("PixelArt","wallu.png"),
os.path.join("PixelArt","wallr.png"),
os.path.join("PixelArt","walld.png"),
os.path.join("PixelArt","wallv.png"),
os.path.join("PixelArt","wallf.png"),
os.path.join("PixelArt","wallg.png")]


class WallTile(Tile):
    """Subclass which calls tile superclass constructor to initiate"""
    key = "Wall"
    def __init__(self, x, y, dir = 0):
        super(WallTile, self).__init__("X", path[dir], False, x, y)#hook up image
