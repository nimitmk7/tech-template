#ifndef NOTIFIER_H
#define NOTIFIER_H

class Notifier {
    private:
        int threshold;
        bool notified;
    public:
        Notifier(int thresh);
        void checkAndNotify(int result);
        bool wasNotified() const;
    };


#endif