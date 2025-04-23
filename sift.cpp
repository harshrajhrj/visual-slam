#include <iostream>
#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "SIFT algorithm\n";
    cv::Mat img = cv::imread("home.jpg");
    cout << "image size: " << img.size << "\n";
    cv::Mat imgGray = img.clone();
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    cv::Ptr<cv::SIFT> detector = cv::SIFT::create();
    vector<cv::KeyPoint> keypoints;
    detector->detect(imgGray, keypoints);
    cv::KeyPoint keypoint = keypoints.at(0);
    cout << "keypoints[0]:\n";
    cout << "\t class_id: \t" << keypoint.class_id << "\n";
    cout << "\t angle: \t" << keypoint.angle << "\n";
    cout << "\t octave: \t" << keypoint.octave << "\n";
    cout << "\t pt: \t\t" << keypoint.pt << "\n";
    cout << "\t size: \t\t" << keypoint.size << "\n";
    cout << "\t response: \t" << keypoint.response << "\n";
    cv::Mat annotatedImg = img.clone();
   cv::drawKeypoints(img, keypoints, annotatedImg, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    cv::imwrite("sift_keypoints.jpg", annotatedImg);
    return 0;
}
