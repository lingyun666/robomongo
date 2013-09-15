#pragma once

#include <QFrame>
QT_BEGIN_NAMESPACE
class QSplitter;
QT_END_NAMESPACE

#include "robomongo/core/domain/MongoShellResult.h"
#include "robomongo/gui/ViewMode.h"

namespace Robomongo
{
    class OutputItemContentWidget;
    class ProgressBarPopup;
    class MongoShell;

    class OutputWidget : public QFrame
    {
        Q_OBJECT

    public:
        explicit OutputWidget(QWidget *parent = 0);

        void present(MongoShell *shell, const std::vector<MongoShellResult> &documents);
        void updatePart(int partIndex, const MongoQueryInfo &queryInfo, const std::vector<MongoDocumentPtr> &documents);
        void toggleOrientation();

        void enterTreeMode();
        void enterTextMode();
        void enterTableMode();
        void enterCustomMode();

        int resultIndex(OutputItemContentWidget *result);

        void showProgress();
        void hideProgress();

    private Q_SLOTS:
        void maximizePart(OutputItemContentWidget *result);
        void restoreSize();

    private:
        std::vector<ViewMode> clearAllParts();
        void tryToMakeAllPartsEqualInSize();
        QSplitter *_splitter;
        ProgressBarPopup *_progressBarPopup;
    };
}
