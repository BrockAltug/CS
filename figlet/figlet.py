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
        figlet = pyfiglet.Figlet(font=font_name)
    else:
        text = pyfiglet.Figlet.getFonts()[0]
        figlet = pyfiglet.Figlet(font=text)

    print(figlet.renderText(text))

if __name__ == "__main__":
    main()
