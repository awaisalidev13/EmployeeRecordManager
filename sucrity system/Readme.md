# SecureDatabaseSystem (Security System)

A console-based Employee Records / Login System written in C++. It authenticates
users against a flat-file "database" (`Data.txt`), and gives regular users a
simple info screen while giving the administrator a full CRUD-style menu for
managing employee records (add, update salary/department, search, list,
compute totals, and save changes back to disk).

## Features

**Regular user**
- Log in with an ID and password
- View their own information (ID, name, salary, department)

**Administrator** (logs in with ID `9999` or password `admin123`)
- Add new users (grows the in-memory arrays dynamically)
- Update a user's salary
- Update a user's department
- Compute total salary expense across all users
- List all users
- Search for a user by ID
- List users eligible for a bonus (salary > 5000)
- Save all changes back to `Data.txt`

## Project Structure

```
sucrity system/
├── main.cpp              # Program entry point, login flow, and menus
├── LoginCheck.hpp/.cpp    # ID and password verification
├── Info.hpp/.cpp          # Intro banner and user info display
├── Administrator.hpp/.cpp # Admin operations (add/update/search/save users)
├── Data.txt               # Flat-file "database" of user records
├── Makefile               # Build configuration
└── output/                # Compiled object files and executable (generated)
```

## Data Format

`Data.txt` stores one record per line, preceded by a line with the total
record count:

```
<record_count>
<ID> <Password> <Name> <Department> <Salary>
...
```

Example:
```
100
101 Secur3#1 Alice Engineering 75000
102 Mktg!202 Bob Marketing 62000
...
```

## Building

This project uses a `Makefile` and requires `g++` with C++11 support.

```bash
cd "sucrity system"
make            # builds output/security_system
make run        # builds (if needed) and runs the program
make clean      # removes the output/ directory
make rebuild    # clean + build
```

## Usage

1. Run the executable:
   ```bash
   ./output/security_system
   ```
2. Enter your **ID** when prompted.
3. Enter your **password** when prompted.
4. Depending on the account:
   - **Regular users** see a menu to view their info or log out.
   - **The administrator** sees a menu with the full set of management
     operations listed above.
5. From the admin menu, choose **Save Changes** to persist any edits back to
   `Data.txt`.

## Known Limitations & Security Notes

Despite the project's name, the current implementation has some notable
weaknesses worth being aware of before using it beyond a learning exercise:

- **Plaintext passwords**: passwords are stored and compared in plaintext in
  `Data.txt`, with no hashing or encryption.
- **Hardcoded admin credentials**: the admin ID (`9999`) and password
  (`admin123`) are hardcoded in `Administrator.cpp`.
- **Password bypass for admin**: `LoginSystemPASS` accepts `admin123` as a
  valid password for *any* ID, effectively creating a master password/backdoor
  regardless of which ID was entered at login.
- **No input validation**: numeric/string inputs from `cin` are not validated,
  so malformed input can produce undefined behavior.
- **Raw pointers / manual memory management**: user data is stored in raw
  dynamically-allocated arrays (`int*`, `string*`, `double*`) with manual
  `new`/`delete`, rather than safer containers like `std::vector`.

These would be good next steps if hardening this project for real-world use:
hashing passwords (e.g., bcrypt), removing the universal admin password
bypass, validating all user input, and replacing raw arrays with STL
containers.

## Requirements

- A C++11-compatible compiler (`g++` recommended)
- `make`
