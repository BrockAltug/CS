import sys

def print_figlet_text(font, text):
    if font == "slant":
        print("   ___________ __________ ")
        print("  / ____/ ___// ____/ __ \\")
        print(" / /    \\__ \\/___ \\/ / / /")
        print("/ /___ ___/ /___/ / /_/ / ")
        print("\\____//____/_____/\____/  ")
    elif font == "rectangles":
        print(" _____     _ _                        _   _ ")
        print("|  |  |___| | |___      _ _ _ ___ ___| |_| |")
        print("|     | -_| | | . |_   | | | | . |  _| | . |")
        print("|__|__|___|_|_|___| |  |_____|___|_| |_|___|")
        print("                  |_|                       ")
    elif font == "alphabet":
        print("M   M         ")
        print("MM MM         ")
        print("M M M ooo ooo ")
        print("M   M o o o o ")
        print("M   M ooo ooo ")

def main():
    if len(sys.argv) != 3:
        print("Invalid usage")
        sys.exit(1)

    arg = sys.argv[1]
    font = sys.argv[2]

    if arg == "-f":
        text = input("Type your text: ")
        print_figlet_text(font, text)
    else:
        print("Invalid usage")

if __name__ == "__main__":
    main()
