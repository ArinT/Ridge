__author__ = 'Arin'
from tile import Tile

path = ["pixel_art/rd.png",
        "pixel_art/rdm.png"]


class RoadTile(Tile):
    """Road subclass which calls tile super class to initiate"""
    key = "Road"
    def __init__(self, x, y, num = 0):
        super(RoadTile, self).__init__(0, path[num], True, x, y)#hook up image
