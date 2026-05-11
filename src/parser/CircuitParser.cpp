#include "parser/CircuitParser.hpp"
#include "factory/GateFactory.hpp"

#include <fstream>
#include <stdexcept>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

Circuit CircuitParser::parseFromFile(
    const std::string& filepath
) {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        throw std::runtime_error(
            "Could not open file: " + filepath
        );
    }

    json data;
    file >> data;

    if (!data.contains("signals")) {
        throw std::runtime_error(
            "JSON missing 'signals' field"
        );
    }

    if (!data.contains("components")) {
        throw std::runtime_error(
            "JSON missing 'components' field"
        );
    }

    Circuit circuit;

    for (const auto& signalData : data["signals"]) {
        std::string signalName;
        bool initialValue = false;

        if (signalData.is_string()) {
            signalName = signalData;
        }
        else if (signalData.is_object()) {
            signalName = signalData["name"];

            if (signalData.contains("initial")) {
                initialValue = signalData["initial"];
            }
        }
        else {
            throw std::runtime_error(
                "Invalid signal definition"
            );
        }

        circuit.createSignal(signalName, initialValue);
    }

    for (const auto& componentData : data["components"]) {

        std::string typeString =
            componentData["type"];

        std::string name =
            componentData["name"];

        ComponentType type =
            componentTypeFromString(typeString);

        // NOT gate

        if (type == ComponentType::NOT) {

            std::string inputName =
                componentData["input"];

            std::string outputName =
                componentData["output"];

            Signal& inputSignal =
                circuit.getSignal(inputName);

            Signal& outputSignal =
                circuit.getSignal(outputName);

            auto gate =
                GateFactory::createUnaryGate(
                    type,
                    name,
                    inputSignal,
                    outputSignal
                );

            circuit.addComponent(std::move(gate));
        }

        // Binary gates

        else {

            std::string inputAName =
                componentData["inputs"][0];

            std::string inputBName =
                componentData["inputs"][1];

            std::string outputName =
                componentData["output"];

            Signal& inputA =
                circuit.getSignal(inputAName);

            Signal& inputB =
                circuit.getSignal(inputBName);

            Signal& output =
                circuit.getSignal(outputName);

            auto gate =
                GateFactory::createBinaryGate(
                    type,
                    name,
                    inputA,
                    inputB,
                    output
                );

            circuit.addComponent(std::move(gate));
        }
    }

    return circuit;
}