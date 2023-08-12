# import the sys module to access command-line arguments
import sys
# import the pyfiglet module for rendering text in "figlet" fonts
import pyfiglet

# Define the main function
def main():
    # Check if no command-line arguments are provided
    if len(sys.argv) == 1:
        # Get the list of available fonts and print them
        fonts = pyfiglet.Figlet.getFonts()
        print("Available fonts:", ", ".join(fonts))
    # Check if two command-line arguments are provided and the first one is a font flag
    elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
        # Extract the font name from the command-line arguments
        font_name = sys.argv[2]
        # Prompt the user to input the text to be rendered
        text = input("Type your text: ")
        try:
            # Create a Figlet object with the specified font
            figlet = pyfiglet.Figlet(font=font_name)
            # Render the input text using the chosen font and print the result
            print(figlet.renderText(text))
        except pyfiglet.FontNotFound:
            # Handle the case where an invalid font name is provided
            print("Invalid font name")
            sys.exit(1)
    else:
        # Handle the case where the command-line arguments are invalid
        print("Invalid usage")
        sys.exit(1)

# Check if the script is being run as the main program
if __name__ == "__main__":
    # Call the main function
    main()