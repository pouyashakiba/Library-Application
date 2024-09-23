# Library Management System

## Overview
This project is a **Library Management System** designed to manage books and publications in a library. It provides functionalities for managing library records, including borrowing, returning, and keeping track of library items such as books, newspapers, and magazines.

## Features
- **Add, delete, and update books/publications.**
- **Borrow and return books.**
- **View publication details.**
- **List all available books and publications.**
- **Track overdue books.**
- **Support for different publication types (Books, Magazines).**
- **Custom Menus for navigating the app.**

## Files
The project consists of several C++ source files and header files, along with text files to store records:

### Source Files:
- `Book.cpp`: Handles the book class and its operations.
- `Date.cpp`: Provides date-related functionalities.
- `LibApp.cpp`: Implements the main application logic.
- `Menu.cpp`: Implements the interactive menu system.
- `Publication.cpp`: Manages the publication class.
- `PublicationSelector.cpp`: Handles the selection of publications from a list.
- `Streamable.cpp`: Handles the streamable interface for I/O operations.
- `Utils.cpp`: Provides utility functions used throughout the application.

### Header Files:
- `Book.h`: Defines the book class.
- `Date.h`: Declares date-related functionalities.
- `LibApp.h`: Declares the library application class.
- `Menu.h`: Declares the menu class.
- `Publication.h`: Defines the publication class.
- `PublicationSelector.h`: Declares the publication selector class.
- `Streamable.h`: Declares the streamable interface.
- `Utils.h`: Declares utility functions.

### Data Files:
- `LibRecs.txt`: Contains the library's current book and publication records&#8203;:contentReference[oaicite:0]{index=0}.
- `LibRecsSmall.txt`: A smaller version of the main library records&#8203;:contentReference[oaicite:1]{index=1}.
- `origLibRecs.txt`: The original library records before any modifications&#8203;:contentReference[oaicite:2]{index=2}.
- `origLibRecsSmall.txt`: A smaller original record set for testing purposes&#8203;:contentReference[oaicite:3]{index=3}.

## How to Run
1. Clone the repository.
2. Build the project using a C++ compiler.
3. Run the `LibApp` application, which will provide a command-line interface for managing library operations.

## Dependencies
- C++ Compiler (GCC, Clang, or MSVC).
- No external libraries required.

## Setup Instructions
1. Clone the repository using:
   ```bash
   git clone https://github.com/yourusername/your-repository-name.git
