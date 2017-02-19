#include "modifiedspinbox.h"

modifiedSpinbox::modifiedSpinbox()
{
    // Removes the up/down buttons
    setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Sets number of decimal places
    setDecimals(2);

    //Right justifies the numbers
    setAlignment(Qt::AlignRight);

}
