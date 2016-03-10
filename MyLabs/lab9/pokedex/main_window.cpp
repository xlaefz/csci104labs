#include "main_window.h"

MainWindow::MainWindow()
{
	// Title
	setWindowTitle("Pokedex");



	// Overall layout!
	overallLayout = new QHBoxLayout();
	pokemonDisplayLayout = new QVBoxLayout();
	overallLayout->addLayout(pokemonDisplayLayout);

	// // Selected pokemon display
	pokemonListWidget = new QListWidget();
	connect(pokemonListWidget, SIGNAL(currentRowChanged(int)), this, SLOT(displayPokemon(int)));
	overallLayout->addWidget(pokemonListWidget);

	// Pokemon image
	pokemonImageContainer = new QLabel();
	pokemonDisplayLayout->addWidget(pokemonImageContainer);

	//TODO

	// Pokemon name
	//TODO
	pokemonNameDisplay = new QLabel(" ");
	pokemonDisplayLayout->addWidget(pokemonNameDisplay);

	// Make it so image and name are at the top
	pokemonDisplayLayout->addStretch();




	// // List of all pokemon
	//TODO
	pokemonListWidget = new QListWidget();
	connect(pokemonListWidget, SIGNAL(currentRowChanged(int)), this, SLOT(displayPokemon(int)));
	overallLayout->addWidget(pokemonListWidget);


	// // Form to add pokemon
	// Layout
	formLayout = new QVBoxLayout();
	overallLayout->addLayout(formLayout);


	// Pokemon name label
	pokemonNameLabel = new QLabel("Pokemon's Name:");
	formLayout->addWidget(pokemonNameLabel);

	// Pokemon name input
	//TODO
	pokemonNameInput = new QLineEdit();
	formLayout->addWidget(pokemonNameInput);

	// Image filename label
	imageFilenameLabel = new QLabel("Image Filename:");
	formLayout->addWidget(imageFilenameLabel);

	imageFilenameInput = new QLineEdit();
	formLayout->addWidget(imageFilenameInput);
	// Image filename input
	//TODO


	// Add button
	//TODO
	addButton = new QPushButton("Add Pokemon");
	connect(addButton, SIGNAL(clicked()), this, SLOT(addPokemon()));
	formLayout->addWidget(addButton);



	// Set overall layout
	setLayout(overallLayout);
}

MainWindow::~MainWindow()
{
	// Delete the images
	for(std::vector<QImage*>::iterator i = pokemonImages.begin();
		i != pokemonImages.end();
		++i)
	{
		delete *i;
	}
	//TODO the delete UI objects
}



void MainWindow::addPokemon()
{
	// Do nothing if user left at least one input blank
	//TODO
	if(pokemonNameInput->text().isEmpty() || imageFilenameInput->text().isEmpty())
	{
		return;
	}	

	// // Get form values
	// Pokemon name
	//TODO
	//pokemonNames.push_back(pokemonNameInput->text());
	// Image
	QString filename = imageFilenameInput->text();
	
	QImage* newImage = new QImage();
	newImage->load(imageFilenameInput->text());

	//TODO what should go right here?
	pokemonNames.push_back(pokemonNameInput->text().toStdString());
	pokemonImages.push_back(newImage);

	pokemonListWidget->addItem(pokemonNameInput->text());


	// Create a new list item with the pokemon's name
	//TODO

	pokemonNameInput->setText("");
	imageFilenameInput->setText("");
	// Clear the form inputs
	//TODO
}



void MainWindow::displayPokemon(int pokemonIndex)
{
	// Get the pokemon specified by the index,
	// which is passed into the function when
	// the user clicks on pokemonListWidget


	// Image
	
	// pokemonImages[pokemonIndex]->load(imageFilenameInput[pokemonIndex]);

	pokemonImageContainer->setPixmap(QPixmap::fromImage(*(pokemonImages[pokemonIndex]))); //set image into a label through a pixmap

	// Pokemon name
	//TODO

	QString pokename;
	pokename += " -";
	pokename += QString::fromStdString(pokemonNames[pokemonIndex]);
	pokemonNameDisplay->setText(pokename);
}
