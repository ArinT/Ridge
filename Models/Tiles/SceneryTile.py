__author__ = 'Arin'
from Tile import Tile

path = "PixelArt/tcr.png"


class SceneryTile(Tile):
    """Subclass which calls tile superclass constructor to initiate"""
    key = "Trash Can"
    def __init__(self, x, y):
        super(SceneryTile, self).__init__("X", path, False, x, y)