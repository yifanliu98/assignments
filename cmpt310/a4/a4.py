# a4.py

# ...

# Tic-Tac-Toe board 
# ' ' represents empty, and the first element is always ' '
from random import randrange

board = [' ' for x in range(10)]

def isFull(board):
    return board.count(' ') == 1

def isEmpty(position):
    return board[position] == ' '

def isWinner(theBoard, player):
    return (theBoard[1] == player and theBoard[2] == player and theBoard[3] == player) or \
        (theBoard[4] == player and theBoard[5] == player and theBoard[6] == player) or \
            (theBoard[7] == player and theBoard[8] == player and theBoard[9] == player) or \
                (theBoard[1] == player and theBoard[4] == player and theBoard[7] == player) or \
                    (theBoard[2] == player and theBoard[5] == player and theBoard[8] == player) or \
                        (theBoard[3] == player and theBoard[6] == player and theBoard[9] == player) or \
                            (theBoard[1] == player and theBoard[5] == player and theBoard[9] == player) or \
                                (theBoard[3] == player and theBoard[5] == player and theBoard[7] == player)

def display():
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('-----------')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('-----------')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    return

def insert(position,player):
    board[position] = player
    print('Player \'' + player + '\' insert at position', int(position))
    display()
    return

def userTurn():
    if isFull(board):
        return
    while True:
        position = input('Please select a position to place an \'X\' (1-9): ')
        try:
            position = int(position)
            if position > 0 and position < 10:
                if isEmpty(position):
                    insert(position,'X')
                    return
                else:
                    print('Position', position, 'is not empty!')
            else:
                print('Please type a number within the range!')
        except:
            print('Please type a number!')
    return

def comTurn():
    possiblePosition = [position for position,player in enumerate(board) if player == ' ' and position != 0]

    size = len(possiblePosition)
    score = [0 for x in range(size)]
    for i in range(size):
        for trials in range(10000):
            boardCopy = board[:]
            boardCopy[possiblePosition[i]] = 'O'
            score[i] += randomPlace(boardCopy,'X')
    maxScorePos = score.index(max(score))
    insert(possiblePosition[maxScorePos],'O')
    return

def randomPlace(board,player):
    if isWinner(board,'O'):
        return 1
    elif isWinner(board,'X'):
        return -10
    elif isFull(board):
        return 0

    possiblePosition = [position for position,player in enumerate(board) if player == ' ' and position != 0]
    randomPos = possiblePosition[randrange(len(possiblePosition))]
    board[randomPos] = player
    if player == 'X':
        return randomPlace(board,'O')
    else:
        return randomPlace(board,'X')

def userFirst():
    while not(isFull(board)):
        if not(isWinner(board,'O')):
            userTurn()
        else:
            print('Sorry, player \'O\' won this time!')
            return
        if not(isWinner(board,'X')):
            if isFull(board):
                break
            comTurn()
        else:
            print('You won this time! Good Job!')
            return
    print('Draw!')
    return

def comFirst():
    while not(isFull(board)):
        if not(isWinner(board,'X')):
            comTurn()
        else:
            print('You won this time! Good Job!')
            return
        if not(isWinner(board,'O')):
            if isFull(board):
                break
            userTurn()
        else:
            print('Sorry, player \'O\' won this time!')
            return
    print('Draw!')
    return



def play_a_new_game():
    print('Welcome to Tic-Tac-Toe game!')
    display()
    first = input("Enter 1 to go first. Enter 2 to go last.")
    if first == '1':
        userFirst()
    else:
        comFirst()
    return

if __name__ == '__main__':
  play_a_new_game()
