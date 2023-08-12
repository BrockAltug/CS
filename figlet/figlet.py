import sys
import pyfiglet

def print_usage_and_exit():
    print("Invalid usage")
    sys.exit(1)

def main():
    if len(sys.argv) == 1:
        font_name = None
    elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
        font_name = sys.argv[2]
    else:
        print_usage_and_exit()

    if font_name:
        text = input("Type your text: ")
        try:
            figlet = pyfiglet.Figlet(font=font_name)
            print(figlet.renderText(text))
        except pyfiglet.FontNotFound:
            print("Invalid font name")
            sys.exit(1)
    else:
        fonts = pyfiglet.Figlet.getFonts()
        print("Available fonts:", ", ".join(fonts))

if __name__ == "__main__":
    main()
