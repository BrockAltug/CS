words = set()

def check(word):
    if word.lower() in words:
        return True
    else:
        return False




def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        words.add(line)
        close(file)
        return True





def size():
    ...



def unload():
    ...

