#ifndef FLAGVARIABLE_FLAGVARIABLE_H
#define FLAGVARIABLE_FLAGVARIABLE_H


template <class Var, class FlagStorage>
class FlagVariable {
public:
    FlagVariable() = default;

    explicit FlagVariable(Var var) {
        variable = var;
    }

    explicit FlagVariable(Var *var) {
        variable = *var;
    }

    /**
     * Gets a pointer to the raw variable
     * @return raw variable
     */
    Var *get() {
        return &variable;
    }

    /**
     * Access raw variable's methods directly
     * @return variable to access
     */
    Var * operator->() {
        return &variable;
    }

    void addFlag(FlagStorage flag) {
        flags = flags | flag;
    }

    void removeFlag(FlagStorage flag) {
        if(checkFlag(flag)) {
            flags = flags ^ flag;
        }
    }

    bool checkFlag(FlagStorage flag) {
        return (flags & flag) == flag;
    }

    bool onlyFlag(FlagStorage flag) {
        return flags == flag;
    }

    void setFlag(FlagStorage flag) {
        flags = flag;
    }


//private:
    FlagStorage flags;
    Var variable;

};

#endif //FLAGVARIABLE_FLAGVARIABLE_H
