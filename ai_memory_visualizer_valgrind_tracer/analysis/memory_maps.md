# Memory Maps

## Introduction

This analysis explains how stack memory, heap memory, pointers, aliases, and object lifetimes behave in C programs. Memory behavior must be understood by tracking where each object is stored, when it is created, and when it stops being valid.

## Stack Memory

Local variables are stored in stack frames associated with function calls. A stack frame is created when a function starts executing and its local variables remain valid while that function is active.

When the function returns, its stack frame's lifetime ends. A pointer to a local variable must therefore not be used after the function has returned.

For recursive functions, each recursive call creates its own stack frame. The local variables belonging to different calls are separate objects even when they have the same variable name.

## Heap Memory

Memory allocated with `malloc` is stored in dynamically allocated memory, commonly called the heap. The allocated object remains alive until it is released with `free`.

The pointer returned by `malloc` provides access to the allocated object. Losing the last valid pointer to an allocated object without calling `free` causes a memory leak.

## Pointer Aliasing

Aliasing occurs when two or more pointers refer to the same object.

For example, if `p` and `q` contain the same address, changing the object through `p` also changes what is observed through `q`. The pointers are different variables, but the object they reference is the same.

This distinction is important when determining ownership and deciding which pointer is responsible for releasing dynamically allocated memory.

## Object Lifetime

Every object has a lifetime.

A local stack object normally exists while its containing function is executing. A dynamically allocated object exists from the successful `malloc` call until the corresponding `free`.

After `free(ptr)`, the allocated object no longer has a valid lifetime. Any pointer that still contains its old address is a dangling pointer and must not be dereferenced.

## Memory Ownership

Ownership describes which part of the program is responsible for releasing dynamically allocated memory.

If a function allocates memory and transfers ownership to its caller, the caller becomes responsible for eventually calling `free`. If ownership is not transferred, the allocating code must ensure that the memory is released.

Clear ownership rules prevent memory leaks and double-free errors.

## AI Explanation Review

An AI explanation of memory behavior must not automatically be treated as correct.

A common misleading explanation is that a pointer becomes NULL automatically after `free`. This is incorrect. Calling `free(ptr)` releases the allocated object, but it does not change the pointer variable itself. The pointer still contains the old address unless the program explicitly assigns `NULL` to it.

Therefore, the correct reasoning is that the object has ended its lifetime and the pointer has become a dangling pointer.

Another important correction is that exact stack and heap addresses should not be assumed to have a fixed layout. The important facts are the object's lifetime, storage duration, allocation, deallocation, and relationships between pointers.

## Conclusion

Correct memory analysis requires tracking each object from creation to the end of its lifetime. Stack objects are associated with function execution, while dynamically allocated objects remain alive until they are explicitly released.

Pointer aliasing means that different pointer variables can refer to the same object. After an object is freed, pointers that referred to it cannot safely be dereferenced.

These concepts provide the basis for understanding memory leaks, invalid accesses, use-after-free errors, and segmentation faults.

