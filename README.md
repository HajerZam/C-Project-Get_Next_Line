# C-Project-Get_Next_Line
my second project in 42 common core let's goooooo (๑•̀ ᴗ•́)૭✧

### **1. Understand the Project Goals**

The goal of **get_next_line** is to create a function that reads one line at a time from a file descriptor (or `stdin`) whenever it's called.

### Key Requirements:

1. Read data in chunks using a buffer.
2. Handle lines of any length using dynamic memory allocation.
3. Support multiple file descriptors simultaneously (bonus!!).

---

### **2. Key Concepts**

### 📖 Topics to Master:

1. **File Descriptors**:
    - Understand how file descriptors work in C (`open`, `read`, `close`).
    - `stdin`, `stdout`, and file inputs.
    
    Resource:
               [Understanding File Descriptors](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)
               - https://youtu.be/HQNsriyMhtY?si=k3StboOVk1yzZ7g_
               - https://youtu.be/Hzg3kCHJcxI?si=LXMRD3p6mHkuIsYc
    
3. **Reading Data with Buffers**:
    - Learn how `read` works and how to use it to handle chunks of data.
    - Resource: `man 2 read`
4. **Dynamic Memory Management**:
    - Master `malloc`, `free`, and resizing strings dynamically.
    - Resource: [Dynamic Memory Allocation in C](https://www.tutorialspoint.com/cprogramming/c_dynamic_memory_allocation.htm)
5. **String Manipulation**:
    - Learn functions like `strchr`, `strdup`, `strjoin`, and `strlen`.
    - Resource: Your **libft** functions or [C Library String Functions](https://cplusplus.com/reference/cstring/).
6. **Static Variables**:
    - Use static variables to store persistent data between function calls.
    
    Resource: [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)
    

---

### **3. Resources**

### 📚 Tutorials & Guides:

- **Introduction to get_next_line**: [Complete Guide to GNL (Blog)](https://harm-smits.github.io/42docs/projects/get_next_line)
- **Understanding Buffers**: [How Buffers Work](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)

### 🛠️ Practice:

Write a small program to:

1. Open a file and print its contents using `read` and a buffer.
2. Test reading data in chunks to understand how partial lines behave.

---
### logic of the **get_next_line** function.

---

### 1. **What Is the Goal?**

We want to create a function, `get_next_line(int fd)`, that:

- Reads text **line by line** from a file descriptor.
- Returns one line at a time.
- Handles leftover characters (what’s after `\n`) for the next call.
- Stops reading when there’s nothing left in the file.

---

### 2. **Why a Static Variable?**

The **static variable** is like a “memory” that persists across calls to the same function.

For `get_next_line`, it:

- Stores leftover data that wasn’t returned as part of the previous line.
- Ensures the function can “remember” what it read last time.

Example:

- First call: Reads "Hello\nWorld".
    - Returns: `"Hello\n"`.
    - Stores leftover: `"World"`.
- Second call: Uses leftover `"World"`.
    - Returns: `"World"`.

---

### 3. **What Does `get_next_line` Do?**

### A. **Initialize and Check Validity**

The function starts by:

- Checking if `fd` (file descriptor) or `BUFFER_SIZE` is valid.
- If not, it returns `NULL`.

---

### B. **Read Data into Buffer**

This is where we use the `read` function:

- **Buffer:** A temporary array that stores what we read from the file.
- It reads chunks of `BUFFER_SIZE` bytes from the file descriptor `fd`.

---

### C. **Combine Buffer with Stash**

- **Stash:** The static variable where leftover data is stored.
- If stash already has leftover data, the new buffer is combined with it using `ft_strjoin_free`.

---

### D. **Check for a Newline**

- Look for a `\n` in the stash using `ft_strchr`.
- If we find it:
    - Split the stash into:
        - The part before `\n` (this will be returned as the line).
        - The part after `\n` (this is saved back into the stash for the next call).
- If no `\n` is found, keep reading until one is found or the file ends.

---

### E. **Return the Line**

- If we’ve reached the end of the file, return whatever’s left in the stash as the final line.
- Free memory properly.

---

### 4. **How the Helpers Work**

### A. **ft_strchr**

Finds a `\n` in the stash:

- If it exists, return a pointer to it.
- If not, return `NULL`.

---

### B. **ft_substr**

Extracts a portion of the stash:

- Example: `"Hello\nWorld"` with start=0, length=6 → `"Hello\n"`.

---

### C. **ft_strdup**

Creates a copy of a string.

---

### D. **ft_strjoin_free**

Joins two strings (e.g., stash and buffer) into one:

- Frees the old stash to prevent memory leaks.

---

### 5. **Example Walkthrough**

Let’s say we’re reading a file with this content:

```
Hello\nWorld\n42\n

```

**First Call to `get_next_line`:**

1. Static stash is empty (`stash = NULL`).
2. Read `"Hello\nWorld\n"` into buffer.
3. Combine buffer with stash → `stash = "Hello\nWorld\n"`.
4. Extract `"Hello\n"` as the line.
5. Save `"World\n"` in stash for the next call.
6. Return: `"Hello\n"`.

---

**Second Call to `get_next_line`:**

1. Static stash now contains `"World\n"`.
2. Look for `\n` in the stash → Found!
3. Extract `"World\n"` as the line.
4. Save `""` (empty string) in stash.
5. Return: `"World\n"`.

---

**Third Call to `get_next_line`:**

1. Static stash is empty (`stash = ""`).
2. Read `"42\n"` into buffer.
3. Combine buffer with stash → `stash = "42\n"`.
4. Extract `"42\n"` as the line.
5. Save `""` (empty string) in stash.
6. Return: `"42\n"`.

---

**Fourth Call to `get_next_line`:**

1. Static stash is empty.
2. Read reaches end-of-file (`read` returns 0).
3. Nothing left to return.
4. Return: `NULL`.

---

### 6. **Why This Logic Works**

- The **stash** ensures we don’t lose leftover data.
- The **buffer** ensures efficient reading.
- The **helpers** simplify operations like finding a newline or joining strings.

---

### 7. **Visualizing the Flow**

```
[Buffer] ---> Combined with ---> [Stash]
       ---> Extract Line ---> Return Line
       ---> Save Leftover ---> [Stash for Next Call]

```

---

**Additional Resources:**

- Refer to the official project description for detailed requirements:
- Review example implementations and discussions:
    - 
        
        [GitHub](https://github.com/ayogun/get_next_line?utm_source=chatgpt.com)
        
    - 
        
        [GitHub](https://github.com/nickdotht/get_next_line?utm_source=chatgpt.com)
        
- Read articles discussing strategies for this project:
    - 
        
        [Medium](https://medium.com/%40ayogun/master-file-i-o-operations-with-42s-get-next-line-project-5fb001d1fff5?utm_source=chatgpt.com)
        
    - 
        
        [Medium](https://medium.com/%40ahmed.ezzouine/1337-ft-get-next-line-file-i-o-7f55762e2445?utm_source=chatgpt.com)

    -
- Explanation Video :
              - https://www.youtube.com/watch?v=8E9siq7apUU&pp=ygUKI2xpbmVyZWFkcw%3D%3D     
