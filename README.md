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
    
    Resource: [Understanding File Descriptors](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)
    
2. **Reading Data with Buffers**:
    - Learn how `read` works and how to use it to handle chunks of data.
    - Resource: `man 2 read`
3. **Dynamic Memory Management**:
    - Master `malloc`, `free`, and resizing strings dynamically.
    - Resource: [Dynamic Memory Allocation in C](https://www.tutorialspoint.com/cprogramming/c_dynamic_memory_allocation.htm)
4. **String Manipulation**:
    - Learn functions like `strchr`, `strdup`, `strjoin`, and `strlen`.
    - Resource: Your **libft** functions or [C Library String Functions](https://cplusplus.com/reference/cstring/).
5. **Static Variables**:
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

### **4. Core Steps for Implementation**

### **Step 1: Create the Basic Structure**

- Write a skeleton function:
    
    ```c
    char *get_next_line(int fd)
    {
    	//get creative pal
    }
    
    ```
    
- Test reading from a file and returning a single line.

### **Step 2: Read and Store Data**

- Use `read(fd, buffer, BUFFER_SIZE)` to read chunks of data.
- Store the data in a static variable to handle multiple calls.

### **Step 3: Find and Return a Line**

- Use `strchr` to locate the newline (`\n`) character in the stored buffer.
- Return everything up to the newline and keep the rest for the next call.

### **Step 4: Handle Dynamic Strings**

- Use a helper function like `ft_strjoin` to concatenate buffers dynamically.

### **Step 5: Manage Edge Cases**

- EOF: Return `NULL` when there’s no more data.
- Errors: Handle invalid `fd` or memory allocation failures.
