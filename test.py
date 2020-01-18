if __name__ == "__main__":
    file = open("input.txt", "w")
    file.write("80 9 9 79\n")
    for layer in range(80):
        for element in range(layer + 1):   
            file.write("128 ")
        file.write("\n")


