#include "main_window.h"

MainWindow::MainWindow()
{
	// Overall layout
	overallLayout = new QVBoxLayout();



	// // Image

	// Load image
	image.load("images/redekopp.jpg");

	// Set up imageContainer
	imageContainer = new QLabel(); //we used this in the last lab to show text, but this time for images
	imageContainer->setPixmap(QPixmap::fromImage(image)); //set image into a label through a pixmap
	overallLayout->addWidget(imageContainer);



	// Caption
	captionLabel = new QLabel("Kanye West");
	overallLayout->addWidget(captionLabel);



	// Set overall layout
	setLayout(overallLayout);
}

MainWindow::~MainWindow()
{
	delete imageContainer;
	delete captionLabel;
	delete overallLayout;
}