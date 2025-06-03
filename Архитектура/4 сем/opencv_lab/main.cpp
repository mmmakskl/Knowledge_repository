#include <opencv2/opencv.hpp>
#include <iostream>

void applySepia(cv::Mat& input, cv::Mat& output);
void applyCartoonEffect(cv::Mat& input, cv::Mat& output);
void applyPencilSketch(cv::Mat& input, cv::Mat& output);

int main() {
    // Открываем камеру (индекс 0)
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Ошибка: камера недоступна." << std::endl;
        return -1;
    }

    // Получаем параметры видео (ширина, высота, FPS)
    int width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(cv::CAP_PROP_FPS);
    if (fps <= 0) fps = 30; // Значение по умолчанию

    // Создаем объект для записи видео
    cv::VideoWriter writer;
    writer.open("output.avi", cv::VideoWriter::fourcc('M','J','P','G'), fps, cv::Size(width, height));
    if (!writer.isOpened()) {
        std::cerr << "Ошибка: не удалось создать файл для записи." << std::endl;
        return -1;
    }

    // int screen_width = 1920;
    // int screen_height = 1080;

    cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);
    // cv::resizeWindow("Webcam", screen_width, screen_height);

    // Основной цикл обработки кадров
    cv::Mat frame, processed_frame;
    char current_effect = '1';

    while (true) {
        cap >> frame; // Захват кадра
        if (frame.empty()) break;


        switch (current_effect) {
            case '1':
                cv::GaussianBlur(frame, processed_frame, cv::Size(15, 15), 0); //Размытие по гауссу
                break;
            case '2':
                applySepia(frame, processed_frame); //ЧБ
                break;
            case '3':
                cv::Canny(frame, processed_frame, 100, 200); //Границы объектов
                break;
            case '4':
                cv::bitwise_not(frame, processed_frame); //Негативный
                break;
            case '5':
                applyCartoonEffect(frame, processed_frame); //Мультик нарисованный
                break;
            case '6':
                applyPencilSketch(frame, processed_frame); //Рисунок карандашом чб (типа)
                break;
            default:
                processed_frame = frame.clone();
        }

        cv::putText(processed_frame, "Effect: " + std::string(1, current_effect),
        cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);

        // Показываем результат
        cv::imshow("Webcam", processed_frame);

        // Записываем кадр в файл
        writer.write(processed_frame);

        // Выход по нажатию ESC
        char key = cv::waitKey(33);
        if (key == 27) break; // ESC
        if (key >= '1' && key <= '6') current_effect = key;
    }

    // Освобождаем ресурсы
    cap.release();
    writer.release();
    cv::destroyAllWindows();

    return 0;
}

// Сепия (ретро-эффект)
void applySepia(cv::Mat& input, cv::Mat& output) {
    cv::Mat kernel = (cv::Mat_<float>(3, 3) <<
        0.393, 0.769, 0.189,
        0.349, 0.686, 0.168,
        0.272, 0.534, 0.131);
    cv::transform(input, output, kernel);
}

// Мультипликационный стиль
void applyCartoonEffect(cv::Mat& input, cv::Mat& output) {
    cv::Mat gray, edges;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::medianBlur(gray, gray, 7);
    cv::adaptiveThreshold(gray, edges, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 9, 2);
    cv::cvtColor(edges, edges, cv::COLOR_GRAY2BGR);
    cv::bitwise_and(input, edges, output);
}

// Карандашный рисунок
void applyPencilSketch(cv::Mat& input, cv::Mat& output) {
    cv::Mat gray, inverted;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(21, 21), 0);
    cv::divide(gray, 255 - gray, inverted, 256);
    cv::cvtColor(inverted, output, cv::COLOR_GRAY2BGR);
}