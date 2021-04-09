/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAINVIEWBASE_HPP
#define MAINVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Button.hpp>

class MainViewBase : public touchgfx::View<MainPresenter>
{
public:
    MainViewBase();
    virtual ~MainViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void increaseValue()
    {
        // Override and implement this function in Main
    }

    virtual void decreaseValue()
    {
        // Override and implement this function in Main
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box backgroundBox;
    touchgfx::Image backgroundImage;
    touchgfx::Image counterBackgroundImage;
    touchgfx::TextAreaWithOneWildcard countTxt;
    touchgfx::Button buttonUp;
    touchgfx::Button buttonDown;
    touchgfx::TextAreaWithOneWildcard loggerSPI;

    /*
     * Wildcard Buffers
     */
    static const uint16_t COUNTTXT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar countTxtBuffer[COUNTTXT_SIZE];
    static const uint16_t LOGGERSPI_SIZE = 300;
    touchgfx::Unicode::UnicodeChar loggerSPIBuffer[LOGGERSPI_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MainViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MAINVIEWBASE_HPP
