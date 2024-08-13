
class Player:
    def __init__(self, name):
        self.name = name
        

    def action(self, game, r ,c):
        game.play_action(self, r, c)
        
class Game:
    def __init__(self, player1, player2, n = 3):
        self.players = [player1, player2]
        self.key = ['o', 'x']
        self.board_size = n
        self.board = [['.'] * self.board_size for _ in range(self.board_size)]
        self.turn = 0
        self.in_game = False

    def start_game(self):
        self.in_game = True

    def end_game(self):
        self.in_game = False

    def play_action(self, player, r, c):
        if not self.in_game:
            print("Game not in session!")
            return
        if player != self.players[self.turn]:
            print("Not your turn!")
            return
        if r >= self.board_size or r < 0 or c >= self.board_size or c < 0 or self.board[r][c] != '.':
            print("Invalid move")
            return

        self.board[r][c] = self.key[self.turn]
        self.print_board()
        if self.check_win(player):
            print(f"Player {player.name} won!")
            self.end_game()
            return
        self.turn += 1
        self.turn %= 2

    def print_board(self):
        for row in self.board:
            print("".join(row))
        print("")

    def check_win(self, player):
        ## check rows
        for i in range(self.board_size):
            total = 0
            for j in range(self.board_size):
                if self.board[i][j] == self.key[self.turn]:
                    total += 1
            if total == self.board_size:
                return True
            
        ## check cols
        for i in range(self.board_size):
            total = 0
            for j in range(self.board_size):
                if self.board[j][i] == self.key[self.turn]:
                    total += 1
            if total == self.board_size:
                return True
        ## check diagonals
        total = 0
        for i in range(self.board_size):
            if self.board[i][i] == self.board_size:
                total += 1
        if total == self.board_size:
            return True
        
        total = 0
        for i in range(self.board_size):
            if self.board[i][self.board_size - 1 - i] == self.board_size:
                total += 1
        if total == self.board_size:
            return True
        
        return False
    

def main():
    player1 = Player("wengqi")
    player2 = Player("interviewer")
    game = Game(player1, player2)
    game.start_game()

    player1.action(game, 0, 0)
    player2.action(game, 1, 1)
    player1.action(game, 1, 1)
    player2.action(game, 1, 2)


main()
        
        
