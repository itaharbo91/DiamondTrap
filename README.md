# DiamondTrap - Virtual Inheritance and Multiple Inheritance Exploration

A C++ project demonstrating advanced OOP concepts including virtual inheritance, multiple inheritance, and the Diamond Problem solution using polymorphism.

> **⭐ 100% C++98 Compliant**
> 
> Explores complex inheritance hierarchies with virtual base classes

## 📋 Description

**DiamondTrap** is an educational project that solves the Diamond Problem in C++ through **virtual inheritance**. The project implements a class hierarchy with four robot classes demonstrating:

### Core Features ✅
- **Virtual inheritance** - Solves the Diamond Problem
- **Multiple inheritance** - DiamondTrap inherits from ScavTrap and FragTrap
- **Polymorphism** - Virtual functions and method overriding
- **Inheritance hierarchy** - ClapTrap → ScavTrap, FragTrap → DiamondTrap
- **Operator overloading** - Assignment and copy constructors
- **C++98 standard** - No modern C++ features, strict compilation flags

## 🚀 Compilation

```bash
make          # Compile the project
make clean    # Remove object files
make fclean   # Remove everything including binary
make re       # Recompile from scratch
```

### Requirements

**Linux (Ubuntu/Debian):**
```bash
g++ compiler with C++98 support
Standard C++ library
```

**macOS:**
```bash
clang++ compiler with C++98 support
Standard C++ library
```

## 💻 Usage

```bash
./diamondtrap
```

The program demonstrates:
- Construction and destruction of class hierarchy
- Copy construction and assignment
- Method overriding and polymorphic behavior
- Special abilities from each class

## 🧠 Class Hierarchy: Diamond Problem

### The Diamond Pattern

```
        ClapTrap (Base)
           /  \
          /    \
     ScavTrap  FragTrap
       (virtual)  (virtual)
         \    /
          \  /
       DiamondTrap
```

### The Problem (Without Virtual Inheritance)

Without virtual inheritance, DiamondTrap would have **two copies** of ClapTrap:
```
DiamondTrap
├── ScavTrap
│   └── ClapTrap (FIRST COPY)
└── FragTrap
    └── ClapTrap (SECOND COPY)
```

This causes:
- Ambiguity in member access
- Wasted memory
- Undefined behavior

### The Solution (With Virtual Inheritance)

With virtual inheritance (`virtual public ClapTrap`), there's only **one shared base**:
```
           ClapTrap (Single Instance)
              /  \
             /    \
        ScavTrap  FragTrap
           \    /
            \  /
         DiamondTrap
```

This ensures:
- Single copy of ClapTrap
- Clear member inheritance
- Proper constructor call chain

## 📚 Class Overview

### `ClapTrap` Class (Base)
Base robot class with core statistics and abilities.

**Attributes:**
- `p_name` - Robot name
- `p_hitPoints` - Health points (default: 10)
- `p_energyPoints` - Energy for actions (default: 10)
- `p_attackDamage` - Damage per attack (default: 0)

**Features:**
- Constructors: default, name, name+damage
- Methods: `attack()`, `takeDamage()`, `beRepaired()`
- Operators: assignment, copy constructor

### `ScavTrap` Class (ScavTrap : virtual public ClapTrap)
Guard robot with gatekeeping abilities.

**Unique Features:**
- Gate keeper mode capability
- `guardGate()` - Activates gate keeper mode
- Overrides `attack()` with custom behavior
- Higher hit points (100) than ClapTrap

### `FragTrap` Class (FragTrap : virtual public ClapTrap)
Fragmentation robot with special abilities.

**Unique Features:**
- High-five capability
- `highFivesGuys()` - Requests positive vibes
- Higher attack damage (30) than ClapTrap
- More energy points (100)

### `DiamondTrap` Class (DiamondTrap : public ScavTrap, public FragTrap)
Combines abilities from both ScavTrap and FragTrap through multiple inheritance.

**Unique Features:**
- `p_name` - Separate name (hides base class name)
- `attack()` - Uses ScavTrap's attack implementation
- `whoAmI()` - Displays both DiamondTrap name and ClapTrap origin name
- Inherits: hit points from ScavTrap (100), energy from FragTrap (100), attack damage from FragTrap (30)

**Statistics:**
- Hit points: 100 (from ScavTrap)
- Energy points: 100 (from FragTrap)
- Attack damage: 30 (from FragTrap)

## 📁 Project Structure

```
DiamondTrap/
├── Makefile                    # Build configuration
├── README.md                   # This file
│
├── includes/
│   ├── ClapTrap.hpp           # Base class header
│   ├── ScavTrap.hpp           # Derived class (virtual)
│   ├── FragTrap.hpp           # Derived class (virtual)
│   └── DiamondTrap.hpp        # Multiple inheritance class
│
└── srcs/
    ├── main.cpp               # Demo program
    ├── ClapTrap.cpp           # Base implementation
    ├── ScavTrap.cpp           # ScavTrap implementation
    ├── FragTrap.cpp           # FragTrap implementation
    └── DiamondTrap.cpp        # DiamondTrap implementation
```

## 🧪 Test Cases

The main program demonstrates:

```cpp
// Construction
ClapTrap ct("Clappy");
ScavTrap st("Scavy");
FragTrap ft("Fraggy");
DiamondTrap dt("Diamondy");

// Copy construction
DiamondTrap dt2(dt);
dt2.whoAmI();

// Assignment
DiamondTrap dt3;
dt3 = dt;

// Base actions
ct.attack("target");
st.takeDamage(5);
ft.beRepaired(10);

// Special abilities
st.guardGate();         // ScavTrap special
ft.highFivesGuys();     // FragTrap special
dt.attack("target");    // Uses ScavTrap's attack
dt.whoAmI();            // Shows DiamondTrap's dual identity
```

## 🔧 Implementation Details

### Virtual Inheritance Syntax

```cpp
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
class DiamondTrap : public ScavTrap, public FragTrap { ... };
```

The `virtual` keyword ensures:
- Only one instance of ClapTrap in DiamondTrap
- Constructors are called in correct order
- No ambiguity in member access

### Constructor Initialization Order

```cpp
// DiamondTrap's constructor must initialize ClapTrap directly
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name, 30),    // Direct virtual base init
      ScavTrap(name),
      FragTrap(name),
      p_name(name) { }
```

### Method Overriding

```cpp
// DiamondTrap::attack() uses ScavTrap's implementation
void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);  // Explicitly call ScavTrap version
}
```

### Name Resolution

DiamondTrap has two names to avoid ambiguity:
- `p_name` - DiamondTrap's own name
- `ClapTrap::p_name` - Inherited base class name (set via ClapTrap constructor)

The `whoAmI()` method displays both:
```
DiamondTrap's name: Diamondy
ClapTrap's name: Diamondy
```

## 📊 Technical Specifications

### Compilation Flags

```makefile
-Wall           # Enable all standard warnings
-Wextra         # Enable extra warnings
-Werror         # Treat warnings as errors
-std=c++98      # C++98 standard (no C++11 or later)
```

### Complexity Analysis

- **Memory**: One shared ClapTrap instance (virtual inheritance benefit)
- **Constructor Chain**: Virtual base class initialization happens once
- **Method Resolution**: Uses virtual function dispatch for polymorphism

## 🎓 Educational Value

This project demonstrates:

✅ **Virtual Inheritance** - Solving the Diamond Problem
✅ **Multiple Inheritance** - Inheriting from multiple classes
✅ **Polymorphism** - Virtual functions and method overriding
✅ **Operator Overloading** - Assignment and copy constructors
✅ **Const Correctness** - Proper use of const in methods
✅ **Member Initialization** - Correct constructor initialization order
✅ **Name Resolution** - Handling ambiguous names in hierarchies
✅ **Memory Management** - Proper destruction in virtual hierarchies
✅ **Protected Members** - Inheritance and access control
✅ **Build System** - Professional Makefile with multiple classes

## 🚀 Performance

- **Initialization**: Single ClapTrap instance shared across hierarchy
- **Method calls**: Virtual function dispatch (minimal overhead)
- **Memory**: Optimized through virtual inheritance

## 📝 Common Pitfalls (Handled Correctly)

| Issue | Without Virtual | With Virtual |
|-------|-----------------|--------------|
| Multiple base instances | ❌ Two ClapTraps | ✅ One ClapTrap |
| Name ambiguity | ❌ Which name? | ✅ Clear separation |
| Constructor calls | ❌ Called twice | ✅ Called once |
| Memory waste | ❌ ~2x size | ✅ Optimal size |
| Ambiguous access | ❌ Error | ✅ Virtual lookup |

## 👤 Author

[@itaharbo91](https://github.com/itaharbo91)

---

**GitHub Description**: Advanced C++98 OOP project demonstrating virtual inheritance and multiple inheritance to solve the Diamond Problem. Features ClapTrap base class inherited by ScavTrap and FragTrap, combined in DiamondTrap with polymorphic method dispatch.