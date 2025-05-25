# 🚀 Get_Next_Line Project

My second project in **42 Common Core** — let's goooooo (๑•̀ ᴗ•́)۷✧  
A function that reads a file descriptor line-by-line, handling multiple fds and dynamic memory!

---

## 📊 Project Statistics

| Metric                 | Details               |
|------------------------|-----------------------|
| Project Name           | Get_Next_Line         |
| Functions Implemented  | 1 main + multiple helpers |
| Key Concepts           | File descriptors, buffers, static vars, dynamic memory |
| Bonus                  | Support multiple FDs  |
| Time Spent             | ~2 weeks              |
| Difficulty             | Medium - High         |

---

## 🎯 Project Goals

- Create `get_next_line(int fd)` to read **one line at a time** from any file descriptor or `stdin`.
- Handle files of **any length** using dynamic buffers.
- Support reading from **multiple file descriptors simultaneously** (bonus).

---

## 📚 Key Concepts & Topics

### 1. File Descriptors & I/O

- Understanding `open`, `read`, `close`, and file descriptor basics (`stdin`, `stdout`, etc.).  
- [GeeksforGeeks Guide](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)  
- [YouTube Intro 1](https://youtu.be/HQNsriyMhtY?si=k3StboOVk1yzZ7g_)  
- [YouTube Intro 2](https://youtu.be/Hzg3kCHJcxI?si=LXMRD3p6mHkuIsYc)

### 2. Buffers & Reading Data

- Using `read` to fetch chunks of data.  
- Handling partial reads and incomplete lines.  
- Reference: `man 2 read`

### 3. Dynamic Memory Management

- Allocating and freeing memory dynamically (`malloc`, `free`).  
- Resizing strings as needed.  
- [Tutorialspoint on malloc/free](https://www.tutorialspoint.com/cprogramming/c_dynamic_memory_allocation.htm)

### 4. String Utilities

- Functions like `strchr`, `strdup`, `strjoin`, `strlen`.  
- Use your **libft** or standard C functions.

### 5. Static Variables

- Store leftover data between calls with static variables.  
- [GeeksforGeeks: Static Variables](https://www.geeksforgeeks.org/static-variables-in-c/)

---

## 📝 How `get_next_line` Works — Overview

| Step                      | Explanation |
|---------------------------|-------------|
| **Validate input**        | Check file descriptor and buffer size. |
| **Read into buffer**      | Read chunks of `BUFFER_SIZE` from fd. |
| **Store leftover (stash)**| Save leftover after newline for next call. |
| **Find newline**          | Locate `\n` in stash to separate lines. |
| **Return one line**       | Return extracted line; keep stash for next. |
| **Handle EOF**            | Return `NULL` when no more lines. |

---

## ⚙️ Helpers Used

- `ft_strchr` — Find newline character.  
- `ft_substr` — Extract substring from stash.  
- `ft_strdup` — Duplicate string.  
- `ft_strjoin_free` — Join stash + buffer & free old stash.

---

## 🔍 Example Walkthrough

File content:
Hello\nWorld\n42\n

| Call | Stash (static var)      | Returned Line |
|-------|------------------------|--------------|
| 1     | "Hello\nWorld\n"        | "Hello\n"    |
| 2     | "World\n"               | "World\n"    |
| 3     | "42\n"                  | "42\n"       |
| 4     | (empty, EOF reached)    | `NULL`       |

---

## 🔄 Flowchart of Execution

[Read Buffer] -> Combine with -> [Stash]
-> Extract Line -> Return Line
-> Save leftover -> [Stash for next call]


---

## 📚 Additional Resources

- [Official 42 docs on Get_Next_Line](https://harm-smits.github.io/42docs/projects/get_next_line)  
- [Example GNL repo by ayogun](https://github.com/ayogun/get_next_line?utm_source=chatgpt.com)  
- [Example GNL repo by nickdotht](https://github.com/nickdotht/get_next_line?utm_source=chatgpt.com)  
- [Medium Article #1](https://medium.com/%40ayogun/master-file-i-o-operations-with-42s-get-next-line-project-5fb001d1fff5?utm_source=chatgpt.com)  
- [Medium Article #2](https://medium.com/%40ahmed.ezzouine/1337-ft-get-next-line-file-i-o-7f55762e2445?utm_source=chatgpt.com)  
- [Explanation Video](https://www.youtube.com/watch?v=8E9siq7apUU&pp=ygUKI2xpbmVyZWFkcw%3D%3D)

---

## 💬 Final Thoughts

`get_next_line` pushed my understanding of:

- File I/O at a low level  
- Buffer management and dynamic memory  
- Persistent state with static variables  
- Modular helper functions & clean code structure  

This is a key building block for larger C projects and system programming!

---

> ✧ Questions, feedback, or collabs? Hit me up anytime!  
