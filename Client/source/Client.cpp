#include <Students/Students.hpp>

#include <zmq.hpp>
#include <iostream>
#include <set>

int main() 
{
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_SUB);
    socket.connect("tcp://*:4040");
    socket.set(zmq::sockopt::subscribe, "");

    std::set<Students> students;

    while (true) 
    {
        zmq::message_t zmqMessage;
        socket.recv(zmqMessage, zmq::recv_flags::none);

        std::string message(static_cast<char*>(zmqMessage.data()), zmqMessage.size());
        std::istringstream iss(message);

        Students student;
        iss >> std::get<0>(student.get_info()) >> std::get<1>(student.get_info()) >> std::get<2>(student.get_info())
            >> std::get<3>(student.get_info());

        if (student.validate())
            students.emplace(std::move(student));

        std::cout << "Right now we have a list with some studients:\n";
        for (const auto& s : students) 
            std::cout << s.to_string() << '\n';
    }

    return 0;
}
