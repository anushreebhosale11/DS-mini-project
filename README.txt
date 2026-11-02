HOSPITAL PATIENT QUEUE MANAGEMENT SYSTEM
Data Structures Mini Project — C++

FILES
- hospital_patient_queue.cpp : complete source code

HOW TO RUN
Option 1 — Online compiler:
1. Open an online C++ compiler such as Programiz Online C++ Compiler.
2. Copy all code from hospital_patient_queue.cpp into the editor.
3. Click Run.
4. Use the numbered menu to test the project.

Option 2 — On a computer with g++:
1. Save the source file as hospital_patient_queue.cpp.
2. Open a terminal in that folder.
3. Compile: g++ -std=c++17 hospital_patient_queue.cpp -o hospital_queue
4. Run:
   Windows: hospital_queue.exe
   macOS/Linux: ./hospital_queue

PROJECT LOGIC
- Enqueue: waitingQueue.push(patient)
- Front/Peek: waitingQueue.front()
- Dequeue: waitingQueue.pop()
- Count: waitingQueue.size()
- Empty check: waitingQueue.empty()

IMPORTANT
This is an educational console prototype, not a real hospital system. It uses an in-memory queue, so data is lost when the program exits. It follows FIFO for ordinary consultation and does not handle emergencies or priority triage.
