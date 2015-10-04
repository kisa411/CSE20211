

word = raw_input("Enter a word:")

list = []
start = 0
end = len(word) - 1

def isPalindrome(word):
    global start
    global end
    for letter in word:
        list.append(letter)
    while (start < end):
        if list[start] != list[end]:
            return False
        else:
            return True
        start+=1
        end-=1
        
if isPalindrome(word) == True:
    print "Is palindrome.\n"
else:
    print "Is not a palindrome.\n"
    
isPalindrome(word)