#include "videowidget.h"
#include "ui_videowidget.h"


VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWidget)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);

    connect(m_timer,SIGNAL(timeout()),this,SLOT(updatePicture()));
    connect(ui->startButton,SIGNAL(click()),this,SLOT(startClick()));
    connect(ui->takePhotoButton,SIGNAL(click()),this,SLOT(takePhotoClick()));
    connect(ui->startRecordButton,SIGNAL(click()),this,SLOT(startRecordClick()));
    connect(ui->stopRecordButton,SIGNAL(click()),this,SLOT(stopRecordClick()));



}

void VideoWidget::openCam()
{
    m_ptrVideoCap = std::make_unique<cv::VideoCapture>(1);

    cv::Size frameSize = cv::Size(m_ptrVideoCap->get(cv::CAP_PROP_FRAME_WIDTH),
                                  m_ptrVideoCap->get(cv::CAP_PROP_FRAME_HEIGHT));

    m_ptrFrame = std::make_unique<cv::Mat>(frameSize,CV_8UC3);

    m_timer->start(50);
}

void VideoWidget::takePhotoClick()
{
    std::string photoName = std::to_string(m_takePhotoCount) + ".jpeg";
    cv::cvtColor(*m_ptrFrame,*m_ptrFrame,cv::COLOR_BGR2RGB);
    cv::imwrite(photoName,*m_ptrFrame);
    m_takePhotoCount++;
}

void VideoWidget::startRecordClick()
{
    if(m_connected)
    {
        if(!m_recording)
        {
            m_recording = true;
            qDebug() << "Record Start ...";

            // need video write count;
            //std::string recordFolder=qApp->applicationDirPath().toStdString();
            //recordFolder = recordFolder + recordFileName;

            //std::string videoName = "TMUY_2021_55066_VIDEO" + QDateTime::currentSecsSinceEpoch() + ".avi";
            m_ptrVideoWriter = std::make_unique<cv::VideoWriter>(
                        "TMUY_2021_55066_VIDEO.avi", cv::VideoWriter::fourcc('M','J','P','G'),20.0
                        ,cv::Size(m_ptrVideoCap->get(cv::CAP_PROP_FRAME_WIDTH),
                                  m_ptrVideoCap->get(cv::CAP_PROP_FRAME_HEIGHT)));

        }
    }
    else
    {
        qDebug() << "Camera is not started";
    }
}

void VideoWidget::stopRecordClick()
{
    if(m_recording)
    {
        m_recording = false;
        m_ptrVideoWriter->release();
        ui->stateRecordLabel->setText("Kayıt yok");
        m_ptrVideoWriter.reset();

    }
}

void VideoWidget::startClick()
{
    qDebug()<< "start Click";

    if(!m_connected)
    {
        qDebug() << "Opening Cam";
        m_connected = true;
        openCam();
    }
    else
    {
        qDebug() << "Camera is working also";
    }
}

void VideoWidget::updatePicture()
{
    if(m_connected)
    {
        *m_ptrVideoCap>>*m_ptrFrame;
        cv::cvtColor(*m_ptrFrame,*m_ptrFrame,cv::COLOR_BGR2RGB);
        /*
        cv::Mat resizedImage;
        cv::resize(*m_ptrFrame,resizedImage,cv::Size(241,211));

        m_RenderImage = new QImage((uchar*)m_ptrFrame->data,
                                   m_ptrFrame->cols,m_ptrFrame->rows,
                                   m_ptrFrame->step,QImage::Format_RGB888);

        */

        cv::Mat resizedImage;
        cv::resize(*m_ptrFrame,resizedImage,cv::Size(351,251));

        m_RenderImage = new QImage((uchar*)resizedImage.data,
                                   resizedImage.cols,resizedImage.rows,
                                   resizedImage.step,QImage::Format_RGB888);


        ui->renderLabel->setPixmap(QPixmap::fromImage(*m_RenderImage));

        if(m_recording)
        {
            cv::cvtColor(*m_ptrFrame,*m_ptrFrame,cv::COLOR_BGR2RGB);
            m_ptrVideoWriter->write(*m_ptrFrame);
            ui->stateRecordLabel->setText("Kayıt ediliyor...");
        }
    }
}
VideoWidget::~VideoWidget()
{
    delete ui;
}
