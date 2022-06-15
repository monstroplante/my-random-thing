from instabot import Bot
from PIL import Image, ImageDraw,ImageFont
import random
import os
import shutil
import os 

with open('/home/celian/Desktop/instabot/count.txt') as f:
    contents = f.read()
    contents=int(contents)
    print(contents)

try:
    file_path = "/home/celian/Desktop/instabot/post.jpg.REMOVE_ME"
    os.remove(file_path)
except OSError as e:
    print("Error: %s : %s" % (file_path, e.strerror))
dir_path = "/home/celian/Desktop/instabot/config"
try:
    shutil.rmtree(dir_path)
except OSError as e:
    print("Error: %s : %s" % (dir_path, e.strerror))

print("config delete")
def rmid():
    return random.randint(450, 550)


def rlegl():
    return random.randint(200, 300)


def rlegG():
    return random.randint(700, 800)


def rarm():
    return random.randint(500, 600)


def ralrm():
    return random.randint(175, 275)


def rarrm():
    return random.randint(700, 800)


def rwidtht():
    return random.randint(3, 15)


def rtop():
    return random.randint(25, 75)


def rcolor():
    return random.randint(0x0, 0xFF)

print("function init")

r = random.randint(0,255)
g = random.randint(0,255)
b = random.randint(0,255)
color = (r,g,b)
mid = rmid()
legw = random.randint(mid-10, mid+10)

headbottom = random.randint(255,500)

multiplierleft = random.randint(11,13)/10

multiplierright = random.randint(11,13)/10

headleft = random.randint(500,750)*multiplierleft

headright = random.randint(250,500)/multiplierleft

headtop= random.randint(25,75)

bodydown = random.randint(700,800)

print(color)

print("variable ready")

img = Image.new("RGB", (1000, 1000), 0x000000)

draw = ImageDraw.Draw(img)

font = ImageFont.truetype('/home/celian/Desktop/instabot/BroadwayRegular-7Bpow.ttf', 1500)

draw.text((-10,-10),f'{contents}',font=font,fill=(255,255,255))

draw.line((random.randint(mid-10, mid+10), bodydown, random.randint(mid -10, mid+10), headbottom), fill=color, width=rwidtht())  # corp

draw.line((750, 1000, legw, bodydown), fill=color, width=rwidtht())

draw.line((rlegl(), 1000, legw, bodydown), fill=color, width=rwidtht())

draw.line((ralrm(),headbottom*multiplierleft, rarrm(), headbottom*multiplierright),fill=color, width=rwidtht())  # arm

draw.ellipse((headright, headtop, headleft, headbottom), outline=color, width=rwidtht())


print("image created")

img.save("/home/celian/Desktop/instabot/post.jpg")

print("image saved")

bot = Bot()

bot.login(username="mail@.fr",password="password")

print("login")

# Recommended to put the photo
# you want to upload in the same
# directory where this Python code
# is located else you will have
# to provide full path for the photo
bot.upload_photo("/home/celian/Desktop/instabot/post.jpg",caption=f"{contents} random generated stickman #random #stickman")

print("envoyer")
contents = contents+1
print("/n-----------")
with open('/home/celian/Desktop/instabot/count.txt', 'w') as f:
    f.write(f"{contents}")
