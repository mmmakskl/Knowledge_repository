import sys
import argparse
from PIL import Image, ImageSequence
import numpy as np
import time
import os

try:
    from colorama import init as colorama_init
    colorama_init()
    COLORAMA_OK = True
except ImportError:
    COLORAMA_OK = False


def parse_args():
    p = argparse.ArgumentParser(
        description="Преобразует изображение или GIF в цветной ASCII-арт."
    )
    p.add_argument("input", help="Путь к исходному файлу (изображение или GIF)")
    p.add_argument("-w", "--width", type=int, default=80,
                   help="Ширина в символах (для каждого кадра)")
    p.add_argument("-c", "--chars", default="@%#*+=-:. ",
                   help="Набор ASCII-символов от «тёмного» к «светлому»")
    p.add_argument("--color", action="store_true",
                   help="Использовать цвет из исходного изображения")
    return p.parse_args()


def clear_console():
    os.system('cls' if os.name == 'nt' else 'clear')


def load_and_prepare(img, new_width):
    w, h = img.size
    ratio = h / w
    new_height = int(new_width * ratio * 0.55)
    img_resized = img.resize((new_width, new_height))
    # Цветная версия для ANSI vero-color
    color_arr = np.array(img_resized.convert('RGB'), dtype=int)
    # Грейскейл для яркости
    gray_arr = np.array(img_resized.convert('L'), dtype=int)
    return gray_arr, color_arr


def map_pixels_to_ascii(gray, charset):
    levels = len(charset)
    idx = (gray * (levels - 1)) // 255
    chars = np.array([charset[i] for i in idx.ravel()]).reshape(idx.shape)
    return chars, idx


def render_ascii(chars, idx, color_arr=None, use_color=False):
    """Если use_color, игнорируем серый, берем цвет массива color_arr."""
    lines = []
    h, w = chars.shape
    for y in range(h):
        line = ''
        for x in range(w):
            ch = chars[y, x]
            if use_color and color_arr is not None:
                r, g, b = color_arr[y, x]
                # ANSI true color escape
                line += f"\x1b[38;2;{r};{g};{b}m{ch}\x1b[0m"
            else:
                line += ch
        lines.append(line)
    return '\n'.join(lines)


def save_ascii(text, out_path="output.txt"):
    with open(out_path, "w") as f:
        f.write(text)


def process_static_image(path, args):
    img = Image.open(path)
    gray, color_arr = load_and_prepare(img, args.width)
    chars, idx = map_pixels_to_ascii(gray, args.chars)
    art = render_ascii(chars, idx, color_arr, use_color=args.color)
    clear_console()
    print(art)
    save_ascii(art)


def process_gif(path, args):
    gif = Image.open(path)
    duration = gif.info.get('duration', 100) / 1000.0
    for frame in ImageSequence.Iterator(gif):
        gray, color_arr = load_and_prepare(frame, args.width)
        chars, idx = map_pixels_to_ascii(gray, args.chars)
        art = render_ascii(chars, idx, color_arr, use_color=args.color)
        clear_console()
        print(art)
        time.sleep(duration)


def main():
    args = parse_args()
    if args.input.lower().endswith('.gif'):
        process_gif(args.input, args)
    else:
        process_static_image(args.input, args)
    input("\nНажмите любую клавишу и Enter для выхода…")


if __name__ == "__main__":
    main()
