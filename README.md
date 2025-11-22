# Red-Black Tree Implementation in C

This repository contains a complete Red-Black Tree (RBT) implementation in C.
It follows Emertxe-style modular coding where each function group is kept in
its own source file.

## 📌 Features

- Insert into RBT
- Delete from RBT
- Delete minimum / maximum
- Find minimum / maximum
- Automatic balancing using:
  - Left Rotate
  - Right Rotate
  - Insert Fixup
  - Delete Fixup
- Uses NULL leaves (not sentinel NIL node)
- Color-coded inorder printing

## 📁 File Structure

| File | Description |
|------|-------------|
| `rbt.h` | Common declarations & typedefs |
| `main.c` | User menu + UI |
| `insert.c` | Insert operation |
| `delete.c` | Delete operation |
| `find_min.c` | Find minimum node |
| `find_max.c` | Find maximum node |
| `delete_min.c` | Delete minimum node |
| `delete_max.c` | Delete maximum node |
| `search.c` | BST search |
| `rotate.c` | Left/Right rotations |
| `helpers.c` | create_node, transplant, fixups, tree_minimum etc. |
| `print_tree.c` | Inorder color-coded tree printing |

## 🏗 Build Instructions

