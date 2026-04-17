# 🐧 TuxAnalyzer

**TuxAnalyzer** is a modern C++ command-line tool for analyzing and exploring codebases efficiently.

It helps developers search, inspect, and understand projects using fast file scanning and multi-threaded processing.

---

## ✨ Features

- 🔍 Keyword search across files (e.g., TODO, FIXME)
- 📊 Project statistics (file count, total lines)
- 📁 Detect largest files in a project
- ⚡ Multi-threaded search for high performance
- 🧠 Built with modern C++ (C++17/20)

---

## 🚀 Usage

```bash
tuxanalyzer find "TODO" .
tuxanalyzer stats .
tuxanalyzer largest .
```

---

## 🛠️ Build

```bash
git clone https://github.com/your-username/TuxAnalyzer.git
cd TuxAnalyzer

mkdir build && cd build
cmake ..
cmake --build .
```

---

## 🧠 Concepts Used

- RAII (Resource Management)
- Move Semantics
- STL (vector, algorithms, filesystem)
- C++17 (`std::optional`, structured bindings)
- C++20 (modern design patterns)
- Multi-threading (`std::thread`, mutex)

---

## 📌 Example Output

```bash
[RESULT] Found 3 matches
./src/main.cpp:10 -> int main(int argc, char* argv[])
```

---

## 📄 License

MIT License