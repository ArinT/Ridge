__author__ = 'Arin'
from tile import Tile

path = "pixel_art/gs.png"


class GrassTile(Tile):
    """Subclass which calls tile superclass constructor to initiate"""
    key = "Grass"
    def __init__(self, x, y):
        super(GrassTile, self).__init__(2, path, True, x, y)#hook up image
