__author__ = 'Arin'
import pygame, os, time
from pygame.locals import *
from Controller.Controller import Controller
from Controller.EventHandler import EventHandler
from Models.Map import Map
from View.View import View


#TODO: WISHLIST: More Info pane stats

#TODO: WISHLIST: Add retaliatory strikes?
#TODO: WISHLIST: Dynamic tiles
#TODO: WISHLIST: Faster a*
#TODO: WISHLIST: Pause and exit
#TODO: WISHLIST: Balancing
#TODO: WISHLIST: Map select
#TODO: WISHLIST: Special attack tooltips
#TODO: WISHLIST: Better, prettier maps
#TODO: WISHLIST: Graceful restart
#TODO: WISHLIST: Dict
#TODO: WISHLIST: Executable



def main():
    """Initializes pygame and music and starts the gameloop"""
    pygame.init()
    map = Map(32, 18)
    clock = pygame.time.Clock()
    start_music("sfx/onestop.mid")
    map.generate_from_ascii("Models/Maps/TheBlock.txt")
    map.quick_board_32_18()
    view = View(map)
    ev_handler = EventHandler()
    controller = Controller(view, map)
    ev_handler.register_listener(controller)
    main_menu(clock, view)
    tutorial_screen(clock, view)
    map.switch_turns()
    while 1:
        clock.tick(30)
        view.update_view()
        for event in pygame.event.get():
            ev_handler.post(event)
        if map.sharks_routed() or map.jets_routed():
            break

    end_game(clock,view)
    game_over(clock, view)
def end_game(clock, view):
    whistle = load_sound("sfx/whistle.wav")
    whistle.play()
    start = time.time()
    end = time.time()
    while end-start < 2.:
        view.update_view()
        end = time.time()

def tutorial_screen(clock, view):
    tutorial = load_image("PixelArt/Tutorial.png")
    cont = False
    fade_in(clock, tutorial, view)
    while not cont:
        clock.tick(30)
        view.screen.blit(tutorial,(0,0))
        pygame.display.flip()
        for event in pygame.event.get():
            if event.type == KEYDOWN:
                cont = True


def main_menu(clock, view):
    start = load_image("PixelArt/WWSTG.jpg")
    begin = False
    fade_in(clock, start, view)
    while not begin:
        clock.tick(30)
        view.screen.blit(start,(0,0))
        pygame.display.flip()
        for event in pygame.event.get():
            if event.type == KEYDOWN:
                begin = True
def game_over(clock, view):
    game_over_screen = load_image("PixelArt/WWSTG_GO.jpg")
    start_music("sfx/town.mid")
    end = False
    fade_in(clock,game_over_screen,view)
    while not end:
        clock.tick(30)
        view.screen.blit(game_over_screen, (0, 0))
        pygame.display.flip()
        for event in pygame.event.get():
            if event.type == KEYDOWN:
                end = True
def fade_in(clock, surf, view):
    opacity = 0.
    while opacity <= 255:
        clock.tick(30)
        surf.set_alpha(opacity)
        view.screen.blit(surf, (0, 0))
        pygame.display.flip()
        opacity += 2
        for event in pygame.event.get():
            if event.type == KEYDOWN:
                opacity = 255

def start_music(name):
    """Commence jams"""
    try:
        pygame.mixer.init()
        #Load will fail on Linux
        pygame.mixer.music.load(name)
        pygame.mixer.music.play()
        pygame.mixer.music.set_volume(.5)
    except pygame.error, message:
        print "What happened to the jams, bro?"
        return
        raise SystemError, message
def load_image(name):
    """Basic utility function"""
    try:
        image = pygame.image.load(name)
    except pygame.error, message:
        print 'Cannot load image at:', name
        raise SystemExit, message
    image = image.convert()
    return image
def load_sound(name):
    class NoneSound:
        def play(self): pass
    if not pygame.mixer:
        return NoneSound()
    fullname = os.path.join(os.path.abspath(os.path.curdir), name)
    try:
        sound = pygame.mixer.Sound(fullname)
    except pygame.error and MemoryError, message:
        print 'Cannot load sound:', name
        sound= NoneSound
    return sound
main()
