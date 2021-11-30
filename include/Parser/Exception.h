#pragma once


class FileMalform: virtual public std::exception{

public:
    explicit FileMalform(const std::string& message){
        error_message = std::string("Malformed file:") + message;
    }

    ~FileMalform() noexcept override = default;

    [[nodiscard]] const char* what() const noexcept override {
        return error_message.c_str();
    }

private:
    std::string error_message;
};

class GridMalform: virtual public std::exception{

public:
    explicit GridMalform(const std::string& message){
        error_message = std::string("Malformed level grid:") + message;
    }

    ~GridMalform() noexcept override = default;

    [[nodiscard]] const char* what() const noexcept override {
        return error_message.c_str();
    }

private:
    std::string error_message;
};



