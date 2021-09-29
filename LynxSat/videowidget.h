#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

/*
 * Qt headers
 **/
#include <QWidget>
#include <QList>
#include <QTimer>
#include <QCameraInfo>
#include <QDebug>


#include <memory>
#include <utility>
#include <string>
#include <thread>
/*
 * Opencv headers
 */
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>


namespace Ui {
class VideoWidget;
}

class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *parent = nullptr);
    ~VideoWidget();

    void openCam();
private slots:
    void takePhotoClick();
    void startRecordClick();
    void stopRecordClick();
    void startClick();

    void updatePicture();
private:
    Ui::VideoWidget *ui;

    bool m_connected{false};
    bool m_recording{false};

    QTimer* m_timer;
    QImage* m_RenderImage;

    std::unique_ptr<cv::VideoCapture> m_ptrVideoCap;
    std::unique_ptr<cv::Mat> m_ptrFrame;
    std::unique_ptr<cv::VideoWriter> m_ptrVideoWriter;

    std::string takePhotoFileName;
    std::string recordFileName;



    int m_takePhotoCount{0};
    int m_recordframeCount{0};
};

#endif // VIDEOWIDGET_H
