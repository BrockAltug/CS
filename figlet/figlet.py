import sys
import pyfiglet

def main():
    if len(sys.argv) == 1:
        fonts = pyfiglet.Figlet.getFonts()
        print("Available fonts:", ", ".join(fonts))
    elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
        font_name = sys.argv[2]
        text = input("Type your text: ")
        try:
            figlet = pyfiglet.Figlet(font=font_name)
            print(figlet.renderText(text))
        except pyfiglet.FontNotFound:
            print("Invalid font name")
            sys.exit(1)
    else:
        print("Invalid usage")
        sys.exit(1)

if __name__ == "__main__":
    main()
