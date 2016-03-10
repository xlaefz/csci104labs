#include <QString>
#include <QFont>
#include "post_widget.h"

PostWidget::PostWidget(Post* p) {
	post = p;
	layout = new QGridLayout();
	titleLabel = new QLabel(QString::fromStdString(post->title));
	usernameLabel = new QLabel(QString::fromStdString(post->username));
	subredditLabel = new QLabel(QString::fromStdString(post->subreddit));
	urlLabel = new QLabel(QString::fromStdString(post->url));
	karmaLabel = new QLabel(QString::fromStdString(post->karma));

	// ADD YOUR CODE HERE.
	// Create the suitable labels and add them to GridLayout properly.
}

PostWidget::~PostWidget() {
	delete titleLabel;
	delete usernameLabel;
	delete subredditLabel;
	delete urlLabel;
	delete karmaLabel;
	delete layout;
}