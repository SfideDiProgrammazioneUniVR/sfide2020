def inp():
    return (int(input()))


def main():
    n = inp()

    for i in range(n):
        s=input()
        l=len(s)

        if s[0]==s[l-1]:
            if len(s)%2==0:
                print("Chikapu")
            else:
                print("Bash")
        else:
            if len(s)%2!=0:
                print("Chikapu")
            else:
                print("Bash")
    return

main()