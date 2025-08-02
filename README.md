# Tic-Tac-Toe Game 🎮

A feature-rich command-line Tic-Tac-Toe game written in C, featuring three AI difficulty levels with advanced strategies.

## 🚀 Features

- **Interactive Gameplay**: Clean console interface with visual board representation
- **Symbol Selection**: Choose to play as X or O
- **Three AI Difficulty Levels**:
  - **Easy**: Random moves for beginners
  - **Medium**: Basic strategic AI (win → block → center → corners)
  - **Hard**: Advanced corner strategy with fork prevention
- **Input Validation**: Robust error handling for user inputs
- **Clear Visual Feedback**: Coordinate system and move display

## 🎯 Game Demo

```
Choose your symbol (X/O): X

Choose your difficulty:

1) Easy
2) Normal  
3) Hard
your choice --> 3


BEGIN!!!

 	1		2		3

1	 	|	 	|	 	
   ___________________________________________

2	 	|	 	|	 	
   ___________________________________________

3	 	|	 	|	 	

Choose a position (line,column): (2,2)
```

## 🧠 AI Strategies

### Easy Mode
- Makes completely random valid moves
- Perfect for beginners or casual play

### Medium Mode
- **Priority 1**: Try to win immediately
- **Priority 2**: Block player from winning
- **Priority 3**: Take center position (strategic advantage)
- **Priority 4**: Take corners over edges
- **Fallback**: Random available position

### Hard Mode (Advanced Corner Strategy)
- **Phases 1-2**: Same as Medium (win/block)
- **Opening**: Always starts with a corner for maximum control
- **Corner Strategy**: 
  - Creates multiple winning threats
  - Forms opposite corners for dual-threat scenarios
  - Uses adjacent edges to extend control
  - Prevents player "forks" (multiple winning paths)
- **Defensive Play**: Counters center-first strategies
- **Strategic Depth**: Plans 2-3 moves ahead

## 📁 Project Structure

```
tic-tac-toe/
├── main.c          # Main program entry point
├── functii.h       # Function declarations and prototypes
├── functii.c       # Core game logic implementation
└── README.md       # This file
```

## 🛠️ Installation & Compilation

### Prerequisites
- GCC compiler (or any C compiler)
- Terminal/Command prompt

### Compilation
```bash
# Clone the repository
git clone https://github.com/yourusername/tic-tac-toe.git
cd tic-tac-toe

# Compile the program
gcc -o tictactoe main.c functii.c

# Run the game
./tictactoe
```

### Alternative compilation (with debugging):
```bash
gcc -g -Wall -o tictactoe main.c functii.c
```

## 🎮 How to Play

1. **Start the game**: Run the compiled executable
2. **Choose symbol**: Select X or O (X always goes first)
3. **Select difficulty**: Choose from Easy (1), Normal (2), or Hard (3)
4. **Make moves**: Enter coordinates in format `(row,column)` where both are 1-3
5. **Win conditions**: Get three in a row (horizontal, vertical, or diagonal)

### Input Format Examples:
- `(1,1)` - Top-left corner
- `(2,2)` - Center position  
- `(3,3)` - Bottom-right corner

## 🏆 Winning the Hard Mode

The Hard AI is designed to be challenging but not impossible. Here are some tips:

- **Avoid predictable patterns**: The AI recognizes common strategies
- **Control the center early**: If you go first, consider taking the center
- **Watch for forks**: The AI will try to create situations with multiple winning paths
- **Think defensively**: Block potential threats while building your own

## 🔧 Technical Details

### Key Functions:
- `initBoard()`: Initialize empty 3x3 game board
- `displayBoard()`: Render current board state
- `verifyWin()`: Check for winning conditions
- `getPlayerMove()`: Handle and validate user input
- `EasyMode/MediumMode/HardMode()`: AI decision algorithms
- `gameItself()`: Main game loop controller

### Position Mapping:
The game uses a 0-8 internal position system:
```
0 | 1 | 2
---------
3 | 4 | 5  
---------
6 | 7 | 8
```

Displayed to users as (row, column) coordinates from (1,1) to (3,3).

## 🤝 Contributing

Contributions are welcome! Areas for potential improvement:

- **GUI version**: Implement graphical interface
- **Network play**: Add multiplayer functionality
- **AI improvements**: Implement minimax algorithm
- **Statistics**: Track wins/losses/draws
- **Customization**: Variable board sizes
- **Themes**: Different visual styles

### How to Contribute:
1. Fork the repository
2. Create a feature branch: `git checkout -b feature-name`
3. Commit changes: `git commit -m 'Add feature'`
4. Push to branch: `git push origin feature-name`
5. Submit a Pull Request

## 👨‍💻 Author

Created with ❤️ by Serban Amariei-Hondrea

## 🐛 Known Issues

- None currently known. Please report any bugs in the Issues section.

## 📈 Future Enhancements

- [ ] Minimax algorithm implementation for unbeatable AI
- [ ] Save/load game functionality
- [ ] Tournament mode with multiple rounds
- [ ] AI difficulty customization
- [ ] Move history and undo functionality
- [ ] Cross-platform GUI version

---

**Enjoy the game!** 🎉 If you find this project helpful, please consider giving it a ⭐ on GitHub.
