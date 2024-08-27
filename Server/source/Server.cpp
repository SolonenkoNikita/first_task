#include <StudentsProcessor/StudentsProcessor.hpp>

#include <zmq.hpp>
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    StudentsProcessor processor;
    std::set<Students> students = processor.process_students("student_file_1.txt", "student_file_2.txt");
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PUB);
    socket.bind("tcp://*:4040");

    while (true) 
    {
        for (const auto& student : students) 
        {
            std::string message = student.to_string();
            zmq::message_t zmqMessage(message.size());
            memcpy(zmqMessage.data(), message.c_str(), message.size());

            socket.send(zmqMessage, zmq::send_flags::none);
            std::cout << "The message: " << message << " has been sent!\n";
        }

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}
