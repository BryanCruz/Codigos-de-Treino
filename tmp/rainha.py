#!/bin/python3

def main():
    n = 5
    board = []

    for i in range(n):
        board += [[]]
        for j in range(n):
            board[i] += [0]
    printBoard(board, n)

    printBoard(dfs(board, n), n)


def printBoard(board, n):
    for i in range(n):
        for j in range(n):
            print(("%d" % board[i][j]).zfill(1), end=" ")
        print()

def dfs(s, n):
    for a in acoes(s, n):
        sol = dfs(resultado(s, a, n), n)
        if atingiuObj(sol, n):
            return sol
    return s

def cloneBoard(board, n):
    newBoard = list(board)
    for i in range(n):
        newBoard[i] = list(board[i])

def resultado(s, a, n):
    i = a[0]
    j = a[1]
    newS = cloneBoard(s, n)
    newS[i][j] = 1

    return newS

def allowed(s, iA, jA, n):
    countV  = 0
    countH  = 0
    countD1 = 0
    countD2 = 0

    for i in range(n):
        countV = countV + s[i][jA]
        countH = countH + s[iA][i]

        if(iA-i >= 0 and jA-i >= 0):
            countD1 = countD1 + s[iA-i][jA-i]
        if(iA+

        if(countV == 1 or countH == 1):
            return False

def acoes(s, n):
    acoesList = [[]]
    for i in range(n):
        for j in range(n):
            if(s[i][j] != 1 and allowed(s, i, j, n)):
                acoesList += [[i, j]]
    return acoesList

def atingiuObj(sol, n):
    count = 0
    for i in range(n):
        for j in range(n):
            count = count + sol[i][j]
            
            if(count == n):
                return True
    return False

if __name__ == '__main__':
   main()
