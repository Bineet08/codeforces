import numpy as np
import random

class TicTacToe:
    def __init__(self):
        self.board = np.zeros((3, 3), dtype=int)  # 0: empty, 1: X, -1: O
        self.reset()

    def reset(self):
        self.board.fill(0)
        return self.get_state()

    def get_state(self):
        # Convert board state to a tuple (immutable)
        return tuple(self.board.flatten())

    def available_moves(self):
        return [(r, c) for r in range(3) for c in range(3) if self.board[r][c] == 0]

    def make_move(self, row, col, player):
        if self.board[row, col] == 0:
            self.board[row, col] = player
            return True
        return False

    def is_winner(self, player):
        for i in range(3):
            if np.all(self.board[i, :] == player) or np.all(self.board[:, i] == player):
                return True
        if np.all(np.diag(self.board) == player) or np.all(np.diag(np.fliplr(self.board)) == player):
            return True
        return False

    def is_draw(self):
        return len(self.available_moves()) == 0 and not self.is_winner(1) and not self.is_winner(-1)

    def print_board(self):
        for row in self.board:
            print(" ".join(['X' if x == 1 else 'O' if x == -1 else '.' for x in row]))
        print()

class QLearningAgent:
    def __init__(self, learning_rate=0.1, discount_factor=0.9, exploration_rate=1.0, exploration_decay=0.995):
        self.q_table = {}  # State-action Q-values
        self.learning_rate = learning_rate
        self.discount_factor = discount_factor
        self.exploration_rate = exploration_rate
        self.exploration_decay = exploration_decay

    def get_q_value(self, state, action):
        return self.q_table.get((state, action), 0.0)

    def choose_action(self, state, available_moves):
        if random.random() < self.exploration_rate:
            return random.choice(available_moves)
        # Exploit learned values
        q_values = [self.get_q_value(state, action) for action in available_moves]
        max_q = max(q_values)
        best_actions = [move for move, q in zip(available_moves, q_values) if q == max_q]
        return random.choice(best_actions)

    def update_q_value(self, state, action, reward, next_state, available_moves):
        best_next_q = max([self.get_q_value(next_state, move) for move in available_moves], default=0.0)
        current_q = self.get_q_value(state, action)
        # Q-Learning formula
        new_q = current_q + self.learning_rate * (reward + self.discount_factor * best_next_q - current_q)
        self.q_table[(state, action)] = new_q

    def decay_exploration(self):
        self.exploration_rate = max(0.1, self.exploration_rate * self.exploration_decay)

# Training the agent
episodes = 10000
game = TicTacToe()
agent = QLearningAgent()

for episode in range(episodes):
    state = game.reset()
    done = False
    player = 1

    while not done:
        available_moves = game.available_moves()
        action = agent.choose_action(state, available_moves)
        game.make_move(action[0], action[1], player)

        next_state = game.get_state()
        reward = 0

        if game.is_winner(player):
            reward = 1 if player == 1 else -1
            done = True
        elif game.is_draw():
            reward = 0.5
            done = True

        agent.update_q_value(state, action, reward, next_state, game.available_moves())

        state = next_state
        player *= -1

    agent.decay_exploration()

print("Training complete!")

# Play against the AI
print("Let's play Tic Tac Toe!")
player_symbol = int(input("Choose your symbol (1 for X, -1 for O): "))
ai_symbol = -player_symbol

game.reset()
while True:
    game.print_board()

    if player_symbol == 1:
        row, col = map(int, input("Enter your move (row and column): ").split())
        if not game.make_move(row, col, player_symbol):
            print("Invalid move. Try again.")
            continue

    if game.is_winner(player_symbol):
        game.print_board()
        print("Congratulations! You win!")
        break

    if game.is_draw():
        game.print_board()
        print("It's a draw!")
        break

    # AI's turn
    state = game.get_state()
    available_moves = game.available_moves()
    if available_moves:  # Check if moves are available
        ai_move = agent.choose_action(state, available_moves)
        game.make_move(ai_move[0], ai_move[1], ai_symbol)

    if game.is_winner(ai_symbol):
        game.print_board()
        print("AI wins! Better luck next time.")
        break

    if game.is_draw():
        game.print_board()
        print("It's a draw!")
        break

    if player_symbol == -1:
        row, col = map(int, input("Enter your move (row and column): ").split())
        if not game.make_move(row, col, player_symbol):
            print("Invalid move. Try again.")
