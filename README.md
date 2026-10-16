# C++ Module 05 — 42 Piscine

Bureaucratic office simulation. Four progressive exercises introducing exception design, inheritance, polymorphism, and factory pattern.

| Ex | Class | Concept |
|---|---|---|
| ex00 | `Bureaucrat` | Custom exceptions (`std::exception`) |
| ex01 | `Form` | Class association, grade validation |
| ex02 | `AForm` + 3 forms | Abstract class, inheritance, polymorphism |
| ex03 | `Intern` | Factory pattern |

**Outcomes:**
- Custom exception classes inheriting from `std::exception` with `what()` override
- `protected` access: open to subclasses, closed to outside
- Abstract class and `= 0` pure virtual method
- Virtual destructor for polymorphic cleanup
- `Intern::makeForm()` string-to-object factory

## Build

```bash
cd cpp5/ex02 && make && ./bureaucrat
```

---

⚠️ **Disclaimer**
This repository contains personal solutions to 42 C++ Piscine exercises for educational and portfolio purposes only. Per 42's honour code, students in the Common Core must write their own solutions without copying. These codes are shared to demonstrate completed work and serve as a reference for future projects.
