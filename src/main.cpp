/** ICP Project 2017/2018: BlockEditor
 * @file main.cpp
 * @brief Application execution point
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "gui/blockeditor.h"
#include <QApplication>

#include "gui/graph_ui.h"

/**
 * @brief Main program block
 * Main was generated by Qt. It parses arguments, sets up the UI and our main widget that contains the scheme.
 * @param argc Argument count
 * @param argv Argument vector
 * @return 0 on success run, others on error
 */
int main(int argc, char *argv[]) {

	QApplication app(argc, argv);

	GraphUI schema;

	BLOCKEDITOR win(schema);

	return app.exec();
}
