#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "barriers.h"
#include "bodie.h"
#include "inset.h"
#include "criticalcurves.h"
#include "ui_mainwindow.h"
#include "roadmap.h"
#include "graphs.h"


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QGraphicsScene* scene;
    QString filename;
    Barriers* barriers;
    Bodie* bodie_1;
    Bodie* bodie_2;
    Inset* inset_1;
    Inset* inset_2;
    CriticalCurves* critical_curves;
    Graphs* graphs;
    RoadMap* path;

public:
    // Constructor.
    MainWindow(QWidget* parent = 0, Qt::WindowFlags flags = 0);
    // Destructor.
    ~MainWindow();

public slots:
    // Scene slot.
    void viewChanged();
    void tabWidgetChanged();
    // File menu slots.
    void open(QString name);
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionQuit_triggered();
    // View menu slot.
    void on_actionFit_triggered();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();

protected:
    Ui::MainWindow * ui;
    void setupUI();

private slots:
    void on_doubleSpinBoxInitialConfigurationFirstBodieX_valueChanged(double x);
    void on_doubleSpinBoxInitialConfigurationFirstBodieY_valueChanged(double y);
    void on_doubleSpinBoxInitialConfigurationSecondBodieX_valueChanged(double x);
    void on_doubleSpinBoxInitialConfigurationSecondBodieY_valueChanged(double y);
    void on_doubleSpinBoxFinalConfigurationFirstBodieX_valueChanged(double x);
    void on_doubleSpinBoxFinalConfigurationFirstBodieY_valueChanged(double y);
    void on_doubleSpinBoxFinalConfigurationSecondBodieX_valueChanged(double x);
    void on_doubleSpinBoxFinalConfigurationSecondBodieY_valueChanged(double y);
    void on_pushButtonSolve_clicked();
    void on_checkBoxShowFirstBodie_stateChanged(int state);
    void on_checkBoxShowSecondBodie_stateChanged(int state);
    void on_checkBoxShowFirstInset_stateChanged(int state);
    void on_checkBoxShowSecondInset_stateChanged(int state);
    void on_checkBoxShowCriticalCurves_stateChanged(int state);
    void on_checkBoxShowGraphs_stateChanged(int state);
};

#endif // MAINWINDOW_H
